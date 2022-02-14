package ru.edu.mirea.pppeis.api.v1.model;

import com.fasterxml.jackson.annotation.JsonInclude;
import lombok.Data;
import lombok.experimental.Accessors;

import java.io.Serializable;
import java.time.LocalDate;
import java.util.List;

import static com.fasterxml.jackson.annotation.JsonInclude.Include.NON_NULL;

@Data
@JsonInclude(NON_NULL)
@Accessors(chain = true)
public class AttendanceQueryResponse
        implements Serializable {
    private static final long serialVersionUID = 475378814538605136L;
    private List<StudentDescription> students;
    private LocalDate fromDate;
    private LocalDate toDate;
    private String lessonTextKeyword;
    private String statusCode;
    private String statusDescription;
}
