package ru.edu.mirea.pppeis.action;

import com.fasterxml.jackson.databind.ObjectMapper;
import lombok.RequiredArgsConstructor;
import org.apache.commons.lang3.tuple.ImmutablePair;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Service;
import ru.edu.mirea.pppeis.storage.attendance.AttendanceService;
import ru.edu.mirea.pppeis.storage.attendance.model.AttendancePg;
import ru.edu.mirea.pppeis.storage.direction.model.DirectionPg;
import ru.edu.mirea.pppeis.storage.group.GroupService;
import ru.edu.mirea.pppeis.storage.group.model.GroupPg;
import ru.edu.mirea.pppeis.storage.lesson.LessonService;
import ru.edu.mirea.pppeis.storage.lesson.model.LessonPg;
import ru.edu.mirea.pppeis.storage.schedule.ScheduleService;
import ru.edu.mirea.pppeis.storage.schedule.model.SchedulePg;
import ru.edu.mirea.pppeis.storage.student.StudentService;
import ru.edu.mirea.pppeis.storage.subject.SubjectService;

import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.time.LocalDate;
import java.time.LocalTime;
import java.time.ZoneId;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import static com.google.common.collect.Lists.newArrayList;
import static java.lang.String.format;
import static java.util.Collections.singletonList;
import static java.util.concurrent.ThreadLocalRandom.current;
import static java.util.stream.Collectors.toList;
import static ru.edu.mirea.pppeis.action.GenerateStudentsAction.getRandomDateInRange;

@Service
@RequiredArgsConstructor
public class GenerateScheduleAction {

    private static final LocalDate periodStart = LocalDate.parse("2021-09-01");
    private static final LocalDate periodEnd = LocalDate.parse("2022-05-31");

    private final ObjectMapper objectMapper;
    private final GroupService groupService;
    private final LessonService lessonService;
    private final SubjectService subjectService;
    private final StudentService studentService;
    private final ScheduleService scheduleService;
    private final AttendanceService attendanceService;

    @Value("${spring.datasource.url}")
    private String jdbcUrl;
    @Value("${spring.datasource.username}")
    private String jdbcUsername;
    @Value("${spring.datasource.password}")
    private String jdbcPassword;

    public void generate() {
        var lessonsBySubjects = getLessons();
        createPartitionedTable();
        createPartitions();
        createLessons(lessonsBySubjects);
        generateSchedule(lessonsBySubjects);
    }

    private Map<String, List<LessonPg>> getLessons() {
        final String lessonsResource = "/initdata/lessons.json";
        var lessonsBySubjects = new HashMap<String, List<LessonPg>>();

        try {
            var node = objectMapper.readTree(GenerateStudyPlanAction.class.getResourceAsStream(lessonsResource));
            for (var subNode : node) {
                List<LessonPg> lessonsList = newArrayList();
                var lessonsNode = subNode.get("lessons");
                for (var lessonNode : lessonsNode) {
                    lessonsList.add(objectMapper.readValue(lessonNode.toPrettyString(), LessonPg.class));
                }
                lessonsBySubjects.put(subNode.get("subject").asText(), lessonsList);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        return lessonsBySubjects;
    }

    private void createLessons(@NonNull Map<String, List<LessonPg>> lessonsBySubjects) {
        lessonsBySubjects.forEach((key, value) -> {
            var savedSubject = subjectService.findByNamePg(key);
            savedSubject.ifPresent(subject -> value.forEach(lesson -> lessonService.createPg(lesson, subject)));
        });
    }

    private void generateSchedule(@NonNull Map<String, List<LessonPg>> lessonsBySubjects) {
        var groupsByLessons = new HashMap<String, List<GroupPg>>();

        lessonsBySubjects.forEach((key, value) -> value.forEach(parsedLesson -> {
            var savedLesson = lessonService.findByNamePg(parsedLesson.getName());
            savedLesson.ifPresent(lesson -> {
                var directionsId = lesson.getSubject().getCourse().getDirections()
                        .stream()
                        .map(DirectionPg::getId)
                        .collect(toList());

                List<GroupPg> lessonGroups = newArrayList();
                for (var directionId : directionsId) {
                    lessonGroups.addAll(groupService.findAllByDirectionId(directionId));
                }
                groupsByLessons.put(lesson.getName(), lessonGroups);
            });
        }));

        generateAttendance(groupsByLessons);
    }

    private void generateAttendance(@NonNull Map<String, List<GroupPg>> groupsByLessons) {
        groupsByLessons.forEach((key, value) -> {
            final long studyStartDate = periodStart.toEpochDay();
            final long studyEndDate = periodEnd.toEpochDay();
            value.forEach(group -> {
                var pairTime = getPairTime();
                var schedule = new SchedulePg()
                        .setDate(getRandomDateInRange(studyStartDate, studyEndDate))
                        .setTimeFrom(pairTime.left)
                        .setTimeTo(pairTime.right);
                var savedSchedule = scheduleService.createPg(schedule, lessonService.findByNamePg(key).get(), singletonList(group));
                studentService.findAllByGroupIdPg(group.getId())
                        .forEach(student -> {
                            boolean isVisited = current().nextInt(0, 6) <= 3;
                            var attendance = new AttendancePg()
                                    .setVisited(isVisited)
                                    .setDate(savedSchedule.getDate());
                            attendanceService.createPg(attendance, savedSchedule, student);
                        });
            });
        });
    }

    private ImmutablePair<Date, Date> getPairTime() {
        var pairDuration = LocalTime.of(1, 30);
        var pairNumber = current().nextInt(0, 6);
        var lessonStart = LocalTime.of(9, 0);
        var lessonEnd = lessonStart.plusHours(pairDuration.getHour()).plusMinutes(pairDuration.getMinute());
        for (int i = 0; i < pairNumber; i++) {
            lessonStart = lessonStart.plusHours(pairDuration.getHour()).plusMinutes(pairDuration.getMinute());
            lessonEnd = lessonEnd.plusHours(pairDuration.getHour()).plusMinutes(pairDuration.getMinute());
        }

        return ImmutablePair.of(Date.from(LocalDate.EPOCH
                .atTime(lessonStart)
                .atZone(ZoneId.systemDefault())
                .toInstant()), Date.from(LocalDate.EPOCH
                .atTime(lessonEnd)
                .atZone(ZoneId.systemDefault())
                .toInstant()));
    }

    private void createPartitions() {
        int weeks = calcWeeksInStudyPeriod();
        var startDate = periodStart;
        var endDate = startDate.plusDays(7);
        for (int i = 1; i <= weeks; i++) {
            try (Connection connection = DriverManager.getConnection(jdbcUrl, jdbcUsername, jdbcPassword);
                 Statement statement = connection.createStatement()) {
                statement.executeUpdate(format("CREATE TABLE IF NOT EXISTS t_attendance_%d PARTITION OF t_attendance" +
                                " FOR VALUES FROM ('%s') TO ('%s')",
                        i, startDate, endDate));
            } catch (SQLException e) {
                e.printStackTrace();
            }
            startDate = startDate.plusDays(7);
            endDate = endDate.plusDays(7);
        }
    }

    private void createPartitionedTable() {
        try (Connection connection = DriverManager.getConnection(jdbcUrl, jdbcUsername, jdbcPassword);
             Statement statement = connection.createStatement()) {
            statement.executeUpdate("DROP TABLE IF EXISTS t_attendance");
        } catch (SQLException e) {
            e.printStackTrace();
        }

        try (Connection connection = DriverManager.getConnection(jdbcUrl, jdbcUsername, jdbcPassword);
             Statement statement = connection.createStatement()) {
            statement.executeUpdate("CREATE TABLE public.t_attendance" +
                    "(id VARCHAR(255) NOT NULL," +
                    "is_visited BOOLEAN," +
                    "date DATE NOT NULL," +
                    "schedule_id VARCHAR(255) CONSTRAINT attendance_schedule_c REFERENCES t_schedule," +
                    "student_id VARCHAR(255) CONSTRAINT attendance_student_c REFERENCES t_student," +
                    "CONSTRAINT composite_pkey PRIMARY KEY (id, date)" +
                    ") PARTITION BY RANGE (date)");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private int calcWeeksInStudyPeriod() {
        var startDate = periodStart;
        int count = 0;
        while (periodEnd.isAfter(startDate)) {
            startDate = startDate.plusDays(7);
            count++;
        }
        return count;
    }

}
