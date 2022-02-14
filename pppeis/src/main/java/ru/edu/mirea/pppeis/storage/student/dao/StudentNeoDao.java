package ru.edu.mirea.pppeis.storage.student.dao;

import org.springframework.data.neo4j.repository.Neo4jRepository;
import org.springframework.stereotype.Repository;
import ru.edu.mirea.pppeis.storage.student.model.StudentNeo;

@Repository
public interface StudentNeoDao
        extends Neo4jRepository<StudentNeo, String> { }
