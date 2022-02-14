package ru.edu.mirea.pppeis.storage.student.dao;

import org.springframework.data.repository.CrudRepository;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Repository;
import ru.edu.mirea.pppeis.storage.student.model.StudentRedis;

import java.util.Optional;

@Repository
public interface StudentRedisDao
        extends CrudRepository<StudentRedis, String> {

    Optional<StudentRedis> f(@NonNull String pgId);

}
