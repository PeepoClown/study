package ru.edu.mirea.pppeis.storage.lesson.dao;

import org.springframework.data.neo4j.repository.Neo4jRepository;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Repository;
import ru.edu.mirea.pppeis.storage.lesson.model.LessonNeo;

import java.util.Optional;

@Repository
public interface LessonNeoDao
        extends Neo4jRepository<LessonNeo, String> {

    Optional<LessonNeo> findByName(@NonNull String name);

}
