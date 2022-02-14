package ru.edu.mirea.pppeis.storage.attendance.model;

import lombok.Data;
import lombok.experimental.Accessors;
import ru.edu.mirea.pppeis.storage.schedule.model.SchedulePg;
import ru.edu.mirea.pppeis.storage.student.model.StudentPg;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.IdClass;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToOne;
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;
import java.io.Serializable;
import java.util.Date;

import static javax.persistence.FetchType.EAGER;
import static javax.persistence.FetchType.LAZY;

@Data
@Accessors(chain = true)
@Entity(name = "attendance")
@IdClass(AttendanceIdPg.class)
@Table(name = "t_attendance", schema = "public")
public class AttendancePg
        implements Serializable {
    private static final long serialVersionUID = 3988082574031058022L;

    @Id
    @Column(name = "id")
    private String id;
    @Id
    @Column(name = "date")
    @Temporal(TemporalType.DATE)
    private Date date;
    @Column(name = "is_visited")
    private Boolean visited;
    @ManyToOne(targetEntity = StudentPg.class, fetch = EAGER)
    @JoinColumn(name = "student_id")
    private StudentPg student;
    @ManyToOne(targetEntity = SchedulePg.class, fetch = LAZY)
    @JoinColumn(name = "schedule_id")
    private SchedulePg schedule;
}
