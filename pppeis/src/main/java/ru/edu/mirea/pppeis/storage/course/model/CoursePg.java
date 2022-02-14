package ru.edu.mirea.pppeis.storage.course.model;

import lombok.Data;
import lombok.experimental.Accessors;
import ru.edu.mirea.pppeis.storage.direction.model.DirectionPg;
import ru.edu.mirea.pppeis.storage.subject.model.SubjectPg;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.JoinTable;
import javax.persistence.ManyToMany;
import javax.persistence.OneToMany;
import javax.persistence.Table;
import java.io.Serializable;
import java.util.List;

import static javax.persistence.FetchType.EAGER;
import static javax.persistence.FetchType.LAZY;

@Data
@Accessors(chain = true)
@Entity(name = "course")
@Table(name = "t_course", schema = "public")
public class CoursePg
        implements Serializable {
    private static final long serialVersionUID = 1101564999854054910L;

    @Id
    @Column(name = "id")
    private String id;
    @Column(name = "name")
    private String name;
    @Column(name = "cathedra")
    private String cathedra;
    @OneToMany(mappedBy = "course")
    private List<SubjectPg> subjects;

    @ManyToMany(fetch = EAGER)
    @JoinTable(name = "course_direction",
            joinColumns = @JoinColumn(name = "course_id"),
            inverseJoinColumns = @JoinColumn(name = "direction_id"))
    private List<DirectionPg> directions;
}
