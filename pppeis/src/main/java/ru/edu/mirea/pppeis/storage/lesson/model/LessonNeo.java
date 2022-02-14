package ru.edu.mirea.pppeis.storage.lesson.model;

import lombok.Data;
import lombok.experimental.Accessors;
import org.springframework.data.neo4j.core.schema.Id;
import org.springframework.data.neo4j.core.schema.Node;
import org.springframework.data.neo4j.core.schema.Relationship;
import ru.edu.mirea.pppeis.storage.schedule.model.ScheduleNeo;

import java.io.Serializable;
import java.util.List;

import static org.springframework.data.neo4j.core.schema.Relationship.Direction.OUTGOING;

@Data
@Node("lesson")
@Accessors(chain = true)
public class LessonNeo
        implements Serializable {
    private static final long serialVersionUID = 8892674379159413971L;

    @Id
    private String id;
    private String name;
    @Relationship(type = "scheduled", direction = OUTGOING)
    private List<ScheduleNeo> schedules;
}
