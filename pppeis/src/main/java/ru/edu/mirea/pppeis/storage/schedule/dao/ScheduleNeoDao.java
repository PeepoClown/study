package ru.edu.mirea.pppeis.storage.schedule.dao;

import org.springframework.data.neo4j.repository.Neo4jRepository;
import org.springframework.stereotype.Repository;
import ru.edu.mirea.pppeis.storage.schedule.model.ScheduleNeo;

@Repository
public interface ScheduleNeoDao
        extends Neo4jRepository<ScheduleNeo, String> { }
