package ru.edu.mirea.pppeis.api.v1.model;

import com.fasterxml.jackson.annotation.JsonInclude;
import lombok.Data;
import lombok.experimental.Accessors;
import ru.edu.mirea.pppeis.storage.student.model.Gender;

import java.io.Serializable;
import java.time.LocalDate;
import java.util.Date;

import static com.fasterxml.jackson.annotation.JsonInclude.Include.NON_NULL;

@Data
@JsonInclude(NON_NULL)
@Accessors(chain = true)
public class StudentDescription
        implements Serializable {
    private static final long serialVersionUID = -7590296446472990370L;
    private String firstName;
    private String lastName;
    private String middleName;
    private LocalDate birthDate;
    private Gender gender;
    private String groupId;
    private Double attendancePercent;
}
