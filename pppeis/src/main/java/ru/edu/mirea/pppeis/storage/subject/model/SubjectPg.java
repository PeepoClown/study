package ru.edu.mirea.pppeis.storage.subject.model;

import lombok.Data;
import lombok.experimental.Accessors;
import ru.edu.mirea.pppeis.storage.course.model.CoursePg;

import javax.persistence.Column;
import javax.persistence.ElementCollection;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.OrderColumn;
import javax.persistence.Table;
import java.io.Serializable;
import java.util.List;

import static javax.persistence.FetchType.EAGER;

@Data
@Accessors(chain = true)
@Entity(name = "subject")
@Table(name = "t_subject", schema = "public")
public class SubjectPg
        implements Serializable {
    private static final long serialVersionUID = 4839018400659468045L;

    @Id
    @Column(name = "id")
    private String id;
    @Column(name = "name")
    private String name;
    @Column(name = "duration")
    private Integer duration;
    @ElementCollection
    @OrderColumn(name = "pos")
    @Column(name = "semesters")
    private List<Integer> semesters;
    @ManyToOne(targetEntity = CoursePg.class, fetch = EAGER)
    @JoinColumn(name = "course_id")
    private CoursePg course;
}
