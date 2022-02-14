package ru.edu.mirea.pppeis.storage.student.model;

import lombok.Data;
import lombok.experimental.Accessors;
import org.springframework.data.redis.core.RedisHash;

import java.io.Serializable;
import java.time.LocalDate;

@Data
@RedisHash("student")
@Accessors(chain = true)
public class StudentRedis
        implements Serializable {
    private static final long serialVersionUID = -4829680370100976695L;

    private String id;
    private String pgId;
    private String firstName;
    private String lastName;
    private String middleName;
    private LocalDate birthDate;
    private Gender gender;
    private String groupId;
    private Double attendancePercent;
}
