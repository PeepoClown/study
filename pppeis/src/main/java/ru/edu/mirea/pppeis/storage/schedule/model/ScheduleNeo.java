package ru.edu.mirea.pppeis.storage.schedule.model;

import lombok.Data;
import lombok.experimental.Accessors;
import org.springframework.data.neo4j.core.schema.Id;
import org.springframework.data.neo4j.core.schema.Node;
import org.springframework.data.neo4j.core.schema.Relationship;
import ru.edu.mirea.pppeis.storage.group.model.GroupNeo;

import java.io.Serializable;
import java.time.LocalDate;
import java.util.List;

import static org.springframework.data.neo4j.core.schema.Relationship.Direction.OUTGOING;

@Data
@Node("schedule")
@Accessors(chain = true)
public class ScheduleNeo
        implements Serializable {
    private static final long serialVersionUID = -8903932754479363260L;

    @Id
    private String id;
    private LocalDate date;
    @Relationship(type = "attends", direction = OUTGOING)
    private List<GroupNeo> groups;
}
