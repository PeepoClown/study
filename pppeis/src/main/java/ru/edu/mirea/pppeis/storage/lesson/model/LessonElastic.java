package ru.edu.mirea.pppeis.storage.lesson.model;

import lombok.Data;
import lombok.experimental.Accessors;
import org.springframework.data.elasticsearch.annotations.Document;
import org.springframework.data.elasticsearch.annotations.Field;

import java.io.Serializable;

import static org.springframework.data.elasticsearch.annotations.FieldType.Auto;
import static org.springframework.data.elasticsearch.annotations.FieldType.Text;

@Data
@Accessors(chain = true)
@Document(indexName = "lesson")
public class LessonElastic
        implements Serializable {
    private static final long serialVersionUID = 2685485453171824581L;

    @Field(type = Auto)
    private String id;
    @Field(type = Auto)
    private String name;
    @Field(type = Text)
    private String text;
}
