package ru.edu.mirea.pppeis.storage.direction.dao;

import org.springframework.data.repository.CrudRepository;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Repository;
import ru.edu.mirea.pppeis.storage.direction.model.DirectionPg;

import java.util.Optional;

@Repository
public interface DirectionPgDao
        extends CrudRepository<DirectionPg, String> {

    Optional<DirectionPg> findByName(@NonNull String name);

}
