package ru.edu.mirea.pppeis.storage.schedule;

import lombok.RequiredArgsConstructor;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Service;
import ru.edu.mirea.pppeis.storage.group.model.GroupNeo;
import ru.edu.mirea.pppeis.storage.group.model.GroupPg;
import ru.edu.mirea.pppeis.storage.lesson.model.LessonPg;
import ru.edu.mirea.pppeis.storage.schedule.dao.ScheduleNeoDao;
import ru.edu.mirea.pppeis.storage.schedule.dao.SchedulePgDao;
import ru.edu.mirea.pppeis.storage.schedule.model.ScheduleNeo;
import ru.edu.mirea.pppeis.storage.schedule.model.SchedulePg;

import java.util.List;
import java.util.UUID;

@Service
@RequiredArgsConstructor
public class ScheduleService {

    private final SchedulePgDao schedulePgDao;
    private final ScheduleNeoDao scheduleNeoDao;

    @NonNull
    public SchedulePg createPg(@NonNull SchedulePg schedule,
                               @NonNull LessonPg lesson,
                               @NonNull List<GroupPg> groups) {
        schedule.setId(UUID.randomUUID().toString());
        schedule.setLesson(lesson);
        schedule.setGroups(groups);
        return schedulePgDao.save(schedule);
    }

    @NonNull
    public ScheduleNeo createNeo(@NonNull ScheduleNeo schedule, @NonNull List<GroupNeo> groups) {
        schedule.setGroups(groups);
        return scheduleNeoDao.save(schedule);
    }

    public List<SchedulePg> findAllByLessonId(@NonNull String lessonId) {
        return schedulePgDao.findAllByLessonId(lessonId);
    }

}
