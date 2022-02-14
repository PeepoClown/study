package ru.edu.mirea.pppeis.action;

import lombok.RequiredArgsConstructor;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Service;
import ru.edu.mirea.pppeis.api.v1.model.AttendanceQueryRequest;
import ru.edu.mirea.pppeis.api.v1.model.AttendanceQueryResponse;
import ru.edu.mirea.pppeis.api.v1.model.StudentDescription;
import ru.edu.mirea.pppeis.storage.attendance.AttendanceService;
import ru.edu.mirea.pppeis.storage.attendance.model.AttendancePg;
import ru.edu.mirea.pppeis.storage.lesson.LessonService;
import ru.edu.mirea.pppeis.storage.student.StudentService;
import ru.edu.mirea.pppeis.storage.student.model.StudentRedis;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Optional;

import static com.google.common.collect.Lists.newArrayList;
import static java.time.ZoneId.systemDefault;
import static java.util.stream.Collectors.toList;

@Service
@RequiredArgsConstructor
public class CalcAttendanceQueryAction {

    private static final List<String> tmpRedisStudents = newArrayList();

    private final LessonService lessonService;
    private final StudentService studentService;
    private final AttendanceService attendanceService;

    @NonNull
    public AttendanceQueryResponse process(@NonNull AttendanceQueryRequest request) {
        studentService.findAllPg()
                .forEach(studentPg -> {
                    var attendaces = attendanceService.findByStudentIdAndDateRangePg(studentPg.getId(),
                            Date.from(request.getFromDate().atStartOfDay().atZone(systemDefault()).toInstant()),
                            Date.from(request.getToDate().atStartOfDay().atZone(systemDefault()).toInstant()));
                    var redisStudent = studentService.createRedis(studentPg, studentPg.getGroup().getName(),
                            calcAttendancePercentage(attendaces));
                    tmpRedisStudents.add(redisStudent.getId());
                });

        return calculate(request);
    }

    @NonNull
    private AttendanceQueryResponse calculate(@NonNull AttendanceQueryRequest request) {
        var studentsId = new ArrayList<String>();
        lessonService.findByTextElastic(request.getLessonTextKeyword())
                .forEach(lessonElastic -> {
                    var lessonNeo1 = lessonService.findByIdNeo(lessonElastic.getId());
                    lessonNeo1.ifPresent(lessonNeo -> lessonNeo.getSchedules()
                                    .stream()
                                    .filter(lesson -> lesson.getDate().compareTo(request.getFromDate()) >= 0)
                                    .filter(lesson -> lesson.getDate().compareTo(request.getToDate()) <= 0)
                                    .forEach(scheduleNeo -> scheduleNeo.getGroups()
                                            .forEach(groupNeo -> groupNeo.getStudents()
                                                    .forEach(student -> studentsId.add(student.getId())))));
                });

        var redisStudents = studentsId
                .stream()
                .map(studentService::findByIdRedis)
                .map(Optional::get)
                .sorted((o1, o2) -> (int) (o1.getAttendancePercent() - o2.getAttendancePercent()))
                .collect(toList());
        tmpRedisStudents.forEach(studentService::deleteByIdRedis);
        return buildResponse(request, redisStudents);
    }

    @NonNull
    private AttendanceQueryResponse buildResponse(@NonNull AttendanceQueryRequest request,
                                                  @NonNull List<StudentRedis> students) {
        var top10Students = students
                .stream()
                .limit(10)
                .map(studentRedis -> new StudentDescription()
                        .setFirstName(studentRedis.getFirstName())
                        .setLastName(studentRedis.getLastName())
                        .setMiddleName(studentRedis.getMiddleName())
                        .setBirthDate(studentRedis.getBirthDate())
                        .setGender(studentRedis.getGender())
                        .setGroupId(studentRedis.getGroupId())
                        .setAttendancePercent(studentRedis.getAttendancePercent()))
                .collect(toList());
        return new AttendanceQueryResponse()
                .setStudents(top10Students)
                .setFromDate(request.getFromDate())
                .setToDate(request.getToDate())
                .setLessonTextKeyword(request.getLessonTextKeyword());
    }

    private double calcAttendancePercentage(@NonNull List<AttendancePg> attendaces) {
        long visitedPairs = attendaces
                .stream()
                .filter(AttendancePg::getVisited)
                .count();
        return 1.0 * visitedPairs / attendaces.size() * 100.0;
    }

}
