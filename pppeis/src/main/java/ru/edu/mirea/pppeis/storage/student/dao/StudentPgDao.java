package ru.edu.mirea.pppeis.storage.student.dao;

import org.springframework.data.repository.CrudRepository;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Repository;
import ru.edu.mirea.pppeis.storage.student.model.StudentPg;

import java.util.List;

@Repository
public interface StudentPgDao
        extends CrudRepository<StudentPg, String> {

    List<StudentPg> findAllByGroupId(@NonNull String groupId);

}
