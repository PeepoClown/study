package ru.edu.mirea.pppeis.storage.group.model;

import lombok.Data;
import lombok.experimental.Accessors;
import ru.edu.mirea.pppeis.storage.direction.model.DirectionPg;
import ru.edu.mirea.pppeis.storage.schedule.model.SchedulePg;
import ru.edu.mirea.pppeis.storage.student.model.StudentPg;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.ManyToMany;
import javax.persistence.ManyToOne;
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;
import java.io.Serializable;
import java.util.Date;
import java.util.List;

import static javax.persistence.FetchType.LAZY;

@Data
@Entity(name = "group")
@Accessors(chain = true)
@Table(name = "t_group", schema = "public")
public class GroupPg
        implements Serializable {
    private static final long serialVersionUID = 7053963093330710226L;

    @Id
    @Column(name = "id")
    private String id;
    @Column(name = "name")
    private String name;
    @Column(name = "email")
    private String email;
    @ManyToOne(targetEntity = StudentPg.class, fetch = LAZY)
    @JoinColumn(name = "group_lead_id")
    private StudentPg groupLead;
    @Column(name = "start_date")
    @Temporal(TemporalType.DATE)
    private Date startDate;
    @Column(name = "end_date")
    @Temporal(TemporalType.DATE)
    private Date endDate;
    @ManyToOne(targetEntity = DirectionPg.class, fetch = LAZY)
    @JoinColumn(name = "direction_id")
    private DirectionPg direction;
    @ManyToMany(mappedBy = "groups")
    private List<SchedulePg> schedules;
}
