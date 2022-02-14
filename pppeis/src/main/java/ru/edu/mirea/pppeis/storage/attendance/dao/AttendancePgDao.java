package ru.edu.mirea.pppeis.storage.attendance.dao;

import io.lettuce.core.dynamic.annotation.Param;
import org.springframework.data.jpa.repository.Query;
import org.springframework.data.repository.CrudRepository;
import org.springframework.lang.NonNull;
import ru.edu.mirea.pppeis.storage.attendance.model.AttendancePg;

import java.util.Date;
import java.util.List;

public interface AttendancePgDao
        extends CrudRepository<AttendancePg, String> {

    @Query("SELECT a FROM attendance a WHERE a.student.id = :studentId AND a.date >= :fromDate AND a.date <= :toDate")
    List<AttendancePg> findByStudentIdAndDateRange(@NonNull @Param("studentId") String studentId,
                                                   @NonNull @Param("fromDate") Date fromDate,
                                                   @NonNull @Param("toDate") Date toDate);

}
