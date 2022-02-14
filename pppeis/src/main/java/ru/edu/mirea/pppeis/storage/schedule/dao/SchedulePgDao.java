package ru.edu.mirea.pppeis.storage.schedule.dao;

import org.springframework.data.repository.CrudRepository;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Repository;
import ru.edu.mirea.pppeis.storage.schedule.model.SchedulePg;

import java.util.List;

@Repository
public interface SchedulePgDao
        extends CrudRepository<SchedulePg, String> {

    List<SchedulePg> findAllByLessonId(@NonNull String lessonId);

}
