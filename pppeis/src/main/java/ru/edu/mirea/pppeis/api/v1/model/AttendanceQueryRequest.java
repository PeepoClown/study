package ru.edu.mirea.pppeis.api.v1.model;

import lombok.Data;
import lombok.experimental.Accessors;

import java.io.Serializable;
import java.time.LocalDate;

@Data
@Accessors(chain = true)
public class AttendanceQueryRequest
        implements Serializable {
    private static final long serialVersionUID = -5944374881592909495L;
    private LocalDate fromDate;
    private LocalDate toDate;
    private String lessonTextKeyword;
}
