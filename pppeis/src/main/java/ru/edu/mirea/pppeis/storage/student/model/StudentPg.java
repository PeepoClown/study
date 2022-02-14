package ru.edu.mirea.pppeis.storage.student.model;

import lombok.Data;
import lombok.experimental.Accessors;
import ru.edu.mirea.pppeis.storage.group.model.GroupPg;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Enumerated;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.Table;
import javax.persistence.Temporal;
import java.io.Serializable;
import java.util.Date;

import static javax.persistence.EnumType.STRING;
import static javax.persistence.FetchType.EAGER;
import static javax.persistence.FetchType.LAZY;
import static javax.persistence.TemporalType.DATE;

@Data
@Accessors(chain = true)
@Entity(name = "student")
@Table(name = "t_student", schema = "public")
public class StudentPg
        implements Serializable {
    private static final long serialVersionUID = 6802226267773457861L;

    @Id
    @Column(name = "id")
    private String id;
    @Column(name = "first_name")
    private String firstName;
    @Column(name = "last_name")
    private String lastName;
    @Column(name = "middle_name")
    private String middleName;
    @Temporal(DATE)
    @Column(name = "birth_date")
    private Date birthDate;
    @Enumerated(STRING)
    @Column(name = "gender")
    private Gender gender;
    @ManyToOne(targetEntity = GroupPg.class, fetch = EAGER)
    @JoinColumn(name = "gruop_id")
    private GroupPg group;
}
