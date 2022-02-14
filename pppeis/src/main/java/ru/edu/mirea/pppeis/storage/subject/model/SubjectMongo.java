package ru.edu.mirea.pppeis.storage.subject.model;

import lombok.Data;
import lombok.experimental.Accessors;
import org.springframework.data.mongodb.core.mapping.Document;
import org.springframework.data.mongodb.core.mapping.Field;

import javax.persistence.Id;
import java.io.Serializable;

@Data
@Accessors(chain = true)
@Document(collection = "subject")
public class SubjectMongo
        implements Serializable {
    private static final long serialVersionUID = 1944655162604871837L;

    @Id
    private String id;
    @Field(name = "name")
    private String name;
    @Field(name = "duration")
    private Integer duration;
}
