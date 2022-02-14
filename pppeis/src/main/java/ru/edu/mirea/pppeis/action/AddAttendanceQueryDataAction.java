package ru.edu.mirea.pppeis.action;

import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;
import ru.edu.mirea.pppeis.storage.course.CourseService;
import ru.edu.mirea.pppeis.storage.group.GroupService;
import ru.edu.mirea.pppeis.storage.group.model.GroupNeo;
import ru.edu.mirea.pppeis.storage.lesson.LessonService;
import ru.edu.mirea.pppeis.storage.lesson.model.LessonNeo;
import ru.edu.mirea.pppeis.storage.schedule.ScheduleService;
import ru.edu.mirea.pppeis.storage.schedule.model.ScheduleNeo;
import ru.edu.mirea.pppeis.storage.student.StudentService;
import ru.edu.mirea.pppeis.storage.student.model.StudentNeo;
import ru.edu.mirea.pppeis.storage.subject.SubjectService;
import ru.edu.mirea.pppeis.storage.subject.model.SubjectMongo;

import java.util.ArrayList;
import java.util.Date;

import static java.time.ZoneId.systemDefault;

@Service
@RequiredArgsConstructor
public class AddAttendanceQueryDataAction {

    private final GroupService groupService;
    private final CourseService courseService;
    private final LessonService lessonService;
    private final SubjectService subjectService;
    private final StudentService studentService;
    private final ScheduleService scheduleService;

    public void generate() {
        lessonService.findAllPg()
                .forEach(lessonPg -> {
                    var schedules = scheduleService.findAllByLessonId(lessonPg.getId());
                    var schedulesNeo = new ArrayList<ScheduleNeo>();
                    schedules.forEach(schedulesPg -> {
                        var groupsNeo = new ArrayList<GroupNeo>();
                        schedulesPg.getGroups()
                                .forEach(groupPg -> {
                                    var studentsNeo = new ArrayList<StudentNeo>();
                                    studentService.findAllByGroupIdPg(groupPg.getId())
                                            .forEach(studentPg -> studentsNeo.add(studentService.createNeo(studentPg.getId())));
                                    groupsNeo.add(groupService.createNeo(new GroupNeo().setId(groupPg.getId()), studentsNeo));
                                });
                        schedulesNeo.add(scheduleService.createNeo(new ScheduleNeo()
                                        .setId(schedulesPg.getId())
                                        .setDate(new Date(schedulesPg.getDate().getTime()).toInstant().atZone(systemDefault()).toLocalDate()),
                                        groupsNeo));
                    });
                    lessonService.createNeo(new LessonNeo().setId(lessonPg.getId()), schedulesNeo);
                });
    }

}
