package ru.edu.mirea.pppeis.storage.direction.model;

import lombok.Data;
import lombok.experimental.Accessors;
import ru.edu.mirea.pppeis.storage.course.model.CoursePg;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.ManyToMany;
import javax.persistence.Table;
import java.io.Serializable;
import java.util.List;

@Data
@Accessors(chain = true)
@Entity(name = "direction")
@Table(name = "t_direction", schema = "public")
public class DirectionPg
        implements Serializable {
    private static final long serialVersionUID = 6086856454795220087L;

    @Id
    @Column(name = "id")
    private String id;
    @Column(name = "name")
    private String name;
    @Column(name = "duration_in_years")
    private Integer durationInYears;

    @ManyToMany(mappedBy = "directions")
    private List<CoursePg> courses;
}
