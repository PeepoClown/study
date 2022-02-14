package ru.edu.mirea.pppeis.storage.direction.model;

import lombok.Data;
import lombok.experimental.Accessors;
import org.springframework.data.mongodb.core.mapping.Document;
import org.springframework.data.mongodb.core.mapping.Field;

import javax.persistence.Id;
import java.io.Serializable;

@Data
@Accessors(chain = true)
@Document(collection = "direction")
public class DirectionMongo
        implements Serializable {
    private static final long serialVersionUID = 4670263909590169791L;

    @Id
    private String id;
    @Field(name = "name")
    private String name;
    @Field(name = "duration_in_years")
    private Integer durationInYears;
}
