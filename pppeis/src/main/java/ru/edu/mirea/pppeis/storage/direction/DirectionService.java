package ru.edu.mirea.pppeis.storage.direction;

import lombok.RequiredArgsConstructor;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Service;
import ru.edu.mirea.pppeis.storage.course.model.CoursePg;
import ru.edu.mirea.pppeis.storage.direction.dao.DirectionPgDao;
import ru.edu.mirea.pppeis.storage.direction.model.DirectionPg;

import java.util.List;
import java.util.Optional;
import java.util.UUID;

@Service
@RequiredArgsConstructor
public class DirectionService {

    private final DirectionPgDao directionPgDao;

    @NonNull
    public DirectionPg createPg(@NonNull DirectionPg direction, @NonNull List<CoursePg> courses) {
        direction.setId(UUID.randomUUID().toString());
        direction.setCourses(courses);
        return directionPgDao.save(direction);
    }

    public Optional<DirectionPg> findByNamePg(@NonNull String name) {
        return directionPgDao.findByName(name);
    }

}
