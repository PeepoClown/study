package ru.edu.mirea.pppeis.storage.attendance;

import lombok.RequiredArgsConstructor;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Service;
import ru.edu.mirea.pppeis.storage.attendance.dao.AttendancePgDao;
import ru.edu.mirea.pppeis.storage.attendance.model.AttendancePg;
import ru.edu.mirea.pppeis.storage.schedule.model.SchedulePg;
import ru.edu.mirea.pppeis.storage.student.model.StudentPg;

import java.util.Date;
import java.util.List;
import java.util.UUID;

@Service
@RequiredArgsConstructor
public class AttendanceService {

    private final AttendancePgDao attendancePgDao;

    @NonNull
    public AttendancePg createPg(@NonNull AttendancePg attendance,
                                 @NonNull SchedulePg schedule,
                                 @NonNull StudentPg student) {
        attendance.setId(UUID.randomUUID().toString());
        attendance.setSchedule(schedule);
        attendance.setStudent(student);
        return attendancePgDao.save(attendance);
    }

    public List<AttendancePg> findByStudentIdAndDateRangePg(@NonNull String studentId,
                                                            @NonNull Date fromDate,
                                                            @NonNull Date toDate) {
        return attendancePgDao.findByStudentIdAndDateRange(studentId, fromDate, toDate);
    }

}
