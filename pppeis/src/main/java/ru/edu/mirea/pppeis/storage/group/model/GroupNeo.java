package ru.edu.mirea.pppeis.storage.group.model;

import lombok.Data;
import lombok.experimental.Accessors;
import org.springframework.data.neo4j.core.schema.Id;
import org.springframework.data.neo4j.core.schema.Node;
import org.springframework.data.neo4j.core.schema.Relationship;
import ru.edu.mirea.pppeis.storage.student.model.StudentNeo;

import java.io.Serializable;
import java.util.List;

import static org.springframework.data.neo4j.core.schema.Relationship.Direction.OUTGOING;

@Data
@Node("group")
@Accessors(chain = true)
public class GroupNeo
        implements Serializable {
    private static final long serialVersionUID = -3072328790867459316L;

    @Id
    private String id;
    @Relationship(type = "consist", direction = OUTGOING)
    private List<StudentNeo> students;
}
