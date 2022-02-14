package ru.edu.mirea.pppeis.storage.schedule.model;

import lombok.Data;
import lombok.experimental.Accessors;
import ru.edu.mirea.pppeis.storage.group.model.GroupPg;
import ru.edu.mirea.pppeis.storage.lesson.model.LessonPg;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.JoinTable;
import javax.persistence.ManyToMany;
import javax.persistence.ManyToOne;
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;
import java.io.Serializable;
import java.util.Date;
import java.util.List;

import static javax.persistence.FetchType.EAGER;
import static javax.persistence.FetchType.LAZY;

@Data
@Accessors(chain = true)
@Entity(name = "schedule")
@Table(name = "t_schedule", schema = "public")
public class SchedulePg
        implements Serializable {
    private static final long serialVersionUID = 1552191839473882156L;

    @Id
    @Column(name = "id")
    private String id;
    @Column(name = "date")
    @Temporal(TemporalType.DATE)
    private Date date;
    @Column(name = "time_from")
    @Temporal(TemporalType.TIME)
    private Date timeFrom;
    @Column(name = "time_to")
    @Temporal(TemporalType.TIME)
    private Date timeTo;
    @ManyToOne(targetEntity = LessonPg.class, fetch = LAZY)
    @JoinColumn(name = "lesson_id")
    private LessonPg lesson;

    @ManyToMany(fetch = EAGER)
    @JoinTable(name = "schedule_group",
            joinColumns = @JoinColumn(name = "schedule_id"),
            inverseJoinColumns = @JoinColumn(name = "group_id"))
    private List<GroupPg> groups;
}
