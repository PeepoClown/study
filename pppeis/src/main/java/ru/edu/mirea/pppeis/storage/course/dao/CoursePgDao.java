package ru.edu.mirea.pppeis.storage.course.dao;

import org.springframework.data.repository.CrudRepository;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Repository;
import ru.edu.mirea.pppeis.storage.course.model.CoursePg;

import java.util.Optional;

@Repository
public interface CoursePgDao
        extends CrudRepository<CoursePg, String> {

    Optional<CoursePg> findByName(@NonNull String name);

}
