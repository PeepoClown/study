package ru.edu.mirea.pppeis.storage.subject;

import lombok.RequiredArgsConstructor;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Service;
import ru.edu.mirea.pppeis.storage.course.model.CoursePg;
import ru.edu.mirea.pppeis.storage.subject.dao.SubjectMongoDao;
import ru.edu.mirea.pppeis.storage.subject.dao.SubjectPgDao;
import ru.edu.mirea.pppeis.storage.subject.model.SubjectMongo;
import ru.edu.mirea.pppeis.storage.subject.model.SubjectPg;

import java.util.List;
import java.util.Optional;
import java.util.UUID;

import static com.google.common.collect.Lists.newArrayList;

@Service
@RequiredArgsConstructor
public class SubjectService {

    private final SubjectPgDao subjectPgDao;
    private final SubjectMongoDao subjectMongoDao;

    @NonNull
    public SubjectPg createPg(@NonNull SubjectPg subject, @NonNull CoursePg course) {
        subject.setId(UUID.randomUUID().toString());
        subject.setCourse(course);
        return subjectPgDao.save(subject);
    }

    @NonNull
    public SubjectMongo createMongo(@NonNull SubjectPg subject) {
        return subjectMongoDao.save(new SubjectMongo()
                .setId(subject.getId())
                .setName(subject.getName())
                .setDuration(subject.getDuration()));
    }

    public Optional<SubjectPg> findByNamePg(@NonNull String name) {
        return subjectPgDao.findByName(name);
    }

    public List<SubjectPg> findAllPg() {
        return newArrayList(subjectPgDao.findAll());
    }

    public List<SubjectPg> findAllByCourseId(@NonNull String courseId) {
        return subjectPgDao.findAllByCourseId(courseId);
    }

}
