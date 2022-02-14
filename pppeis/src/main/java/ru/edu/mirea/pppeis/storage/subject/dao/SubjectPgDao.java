package ru.edu.mirea.pppeis.storage.subject.dao;

import org.springframework.data.repository.CrudRepository;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Repository;
import ru.edu.mirea.pppeis.storage.subject.model.SubjectPg;

import java.util.List;
import java.util.Optional;

@Repository
public interface SubjectPgDao
        extends CrudRepository<SubjectPg, String> {

    Optional<SubjectPg> findByName(@NonNull String name);

    List<SubjectPg> findAllByCourseId(@NonNull String courseId);

}
