package ru.edu.mirea.pppeis.storage.group.dao;

import org.springframework.data.repository.CrudRepository;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Repository;
import ru.edu.mirea.pppeis.storage.group.model.GroupPg;

import java.util.List;
import java.util.Optional;

@Repository
public interface GroupPgDao
        extends CrudRepository<GroupPg, String> {

    Optional<GroupPg> findByName(@NonNull String name);

    List<GroupPg> findAllByDirectionId(@NonNull String directionId);

}
