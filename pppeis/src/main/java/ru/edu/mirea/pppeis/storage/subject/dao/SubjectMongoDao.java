package ru.edu.mirea.pppeis.storage.subject.dao;

import org.springframework.data.mongodb.repository.MongoRepository;
import ru.edu.mirea.pppeis.storage.subject.model.SubjectMongo;

public interface SubjectMongoDao
        extends MongoRepository<SubjectMongo, String> { }
