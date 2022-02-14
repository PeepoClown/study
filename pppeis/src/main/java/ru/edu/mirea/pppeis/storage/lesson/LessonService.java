package ru.edu.mirea.pppeis.storage.lesson;

import lombok.RequiredArgsConstructor;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Service;
import ru.edu.mirea.pppeis.storage.lesson.dao.LessonElasticDao;
import ru.edu.mirea.pppeis.storage.lesson.dao.LessonNeoDao;
import ru.edu.mirea.pppeis.storage.lesson.dao.LessonPgDao;
import ru.edu.mirea.pppeis.storage.lesson.model.LessonElastic;
import ru.edu.mirea.pppeis.storage.lesson.model.LessonNeo;
import ru.edu.mirea.pppeis.storage.lesson.model.LessonPg;
import ru.edu.mirea.pppeis.storage.schedule.model.ScheduleNeo;
import ru.edu.mirea.pppeis.storage.subject.model.SubjectPg;

import java.util.List;
import java.util.Optional;
import java.util.UUID;

import static com.google.common.collect.Lists.newArrayList;

@Service
@RequiredArgsConstructor
public class LessonService {

    private final LessonPgDao lessonPgDao;
    private final LessonNeoDao lessonNeoDao;
    private final LessonElasticDao lessonElasticDao;

    @NonNull
    public LessonPg createPg(@NonNull LessonPg lesson, @NonNull SubjectPg subject) {
        lesson.setId(UUID.randomUUID().toString());
        lesson.setSubject(subject);
        var savedLesson = lessonPgDao.save(lesson);
        lessonElasticDao.save(toLessonElastic(savedLesson));
        return savedLesson;
    }

    @NonNull
    public LessonNeo createNeo(@NonNull LessonNeo lesson, @NonNull List<ScheduleNeo> schedules) {
        lesson.setSchedules(schedules);
        return lessonNeoDao.save(lesson);
    }

    public Optional<LessonPg> findByNamePg(@NonNull String name) {
        return lessonPgDao.findByName(name);
    }

    public Optional<LessonNeo> findByIdNeo(@NonNull String id) {
        return lessonNeoDao.findById(id);
    }

    public Optional<LessonNeo> findByNameNeo(@NonNull String name) {
        return lessonNeoDao.findByName(name);
    }

    public List<LessonPg> findAllPg() {
        return newArrayList(lessonPgDao.findAll());
    }

    public List<LessonElastic> findByTextElastic(@NonNull String textKeyword) {
        return lessonElasticDao.findByTextContains(textKeyword);
    }

    @NonNull
    private LessonElastic toLessonElastic(@NonNull LessonPg lesson) {
        return new LessonElastic()
                .setId(lesson.getId())
                .setName(lesson.getName())
                .setText(lesson.getText());
    }

}
