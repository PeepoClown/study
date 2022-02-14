package ru.edu.mirea.pppeis.storage.course.dao;

import org.springframework.data.mongodb.repository.MongoRepository;
import org.springframework.stereotype.Repository;
import ru.edu.mirea.pppeis.storage.course.model.CourseMongo;

@Repository
public interface CourseMongoDao
        extends MongoRepository<CourseMongo, String> { }
