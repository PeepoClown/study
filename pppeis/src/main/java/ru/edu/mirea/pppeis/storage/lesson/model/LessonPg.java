package ru.edu.mirea.pppeis.storage.lesson.model;

import lombok.Data;
import lombok.experimental.Accessors;
import ru.edu.mirea.pppeis.storage.subject.model.SubjectPg;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.Table;
import java.io.Serializable;

import static javax.persistence.FetchType.EAGER;

@Data
@Accessors(chain = true)
@Entity(name = "lesson")
@Table(name = "t_lesson", schema = "public")
public class LessonPg
        implements Serializable {
    private static final long serialVersionUID = -2327703286369753285L;

    @Id
    @Column(name = "id")
    private String id;
    @Column(name = "name")
    private String name;
    @Column(name = "text", length = 2048)
    private String text;
    @ManyToOne(targetEntity = SubjectPg.class, fetch = EAGER)
    @JoinColumn(name = "subject_id")
    private SubjectPg subject;
}
