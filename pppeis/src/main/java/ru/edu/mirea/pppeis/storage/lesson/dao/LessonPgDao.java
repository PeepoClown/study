package ru.edu.mirea.pppeis.storage.lesson.dao;

import org.springframework.data.repository.CrudRepository;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Repository;
import ru.edu.mirea.pppeis.storage.lesson.model.LessonPg;

import java.util.Optional;

@Repository
public interface LessonPgDao
        extends CrudRepository<LessonPg, String> {

    Optional<LessonPg> findByName(@NonNull String name);

}
