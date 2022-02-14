package ru.edu.mirea.pppeis.storage.student.model;

import lombok.Data;
import lombok.experimental.Accessors;
import org.springframework.data.neo4j.core.schema.Id;
import org.springframework.data.neo4j.core.schema.Node;

import java.io.Serializable;

@Data
@Node("student")
@Accessors(chain = true)
public class StudentNeo
        implements Serializable {
    private static final long serialVersionUID = 6763524478877890721L;

    @Id
    private String id;
}
