package ru.edu.mirea.pppeis.storage.course.model;

import lombok.Data;
import lombok.experimental.Accessors;
import org.springframework.data.mongodb.core.mapping.Document;
import org.springframework.data.mongodb.core.mapping.Field;
import ru.edu.mirea.pppeis.storage.subject.model.SubjectMongo;

import javax.persistence.Id;
import java.io.Serializable;
import java.util.List;

@Data
@Accessors(chain = true)
@Document(collection = "course")
public class CourseMongo
        implements Serializable {
    private static final long serialVersionUID = -359680339620498731L;

    @Id
    private String id;
    @Field(name = "name")
    private String name;
    @Field(name = "cathedra")
    private String cathedra;
    @Field(name = "subjects")
    private List<SubjectMongo> subjects;
}
