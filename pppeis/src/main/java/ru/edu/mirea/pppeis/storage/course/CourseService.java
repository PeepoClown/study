package ru.edu.mirea.pppeis.storage.course;

import lombok.RequiredArgsConstructor;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Service;
import ru.edu.mirea.pppeis.storage.course.dao.CourseMongoDao;
import ru.edu.mirea.pppeis.storage.course.dao.CoursePgDao;
import ru.edu.mirea.pppeis.storage.course.model.CourseMongo;
import ru.edu.mirea.pppeis.storage.course.model.CoursePg;
import ru.edu.mirea.pppeis.storage.direction.model.DirectionPg;
import ru.edu.mirea.pppeis.storage.subject.model.SubjectMongo;

import java.util.List;
import java.util.Optional;
import java.util.UUID;

import static com.google.common.collect.Lists.newArrayList;

@Service
@RequiredArgsConstructor
public class CourseService {

    private final CoursePgDao coursePgDao;
    private final CourseMongoDao courseMongoDao;

    @NonNull
    public CoursePg createPg(@NonNull CoursePg course) {
        course.setId(UUID.randomUUID().toString());
        return coursePgDao.save(course);
    }

    @NonNull
    public CourseMongo createMongo(@NonNull CoursePg coursePg, @NonNull List<SubjectMongo> subjects) {
        return courseMongoDao.save(new CourseMongo()
                .setId(coursePg.getId())
                .setName(coursePg.getName())
                .setCathedra(coursePg.getCathedra())
                .setSubjects(subjects));
    }

    public Optional<CoursePg> findByNamePg(@NonNull String name) {
        return coursePgDao.findByName(name);
    }

    public List<CoursePg> findAllPg() {
        return newArrayList(coursePgDao.findAll());
    }

    public void updateDirectionByNamePg(@NonNull String name, @NonNull List<DirectionPg> directions) {
        var course = findByNamePg(name);
        if (course.isPresent()) {
            course.get().setDirections(directions);
            coursePgDao.save(course.get());
        }
    }

}
