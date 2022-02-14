package ru.edu.mirea.pppeis.storage.group.dao;

import org.springframework.data.neo4j.repository.Neo4jRepository;
import org.springframework.stereotype.Repository;
import ru.edu.mirea.pppeis.storage.group.model.GroupNeo;

@Repository
public interface GroupNeoDao
        extends Neo4jRepository<GroupNeo, String> { }
