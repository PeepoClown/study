package ru.edu.mirea.pppeis.storage.lesson.dao;

import org.springframework.data.elasticsearch.repository.ElasticsearchRepository;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Repository;
import ru.edu.mirea.pppeis.storage.lesson.model.LessonElastic;

import java.util.List;

@Repository
public interface LessonElasticDao
        extends ElasticsearchRepository<LessonElastic, String> {

    List<LessonElastic> findByTextContains(@NonNull String textKeyword);

}
