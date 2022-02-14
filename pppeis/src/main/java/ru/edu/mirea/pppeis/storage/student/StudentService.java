package ru.edu.mirea.pppeis.storage.student;

import lombok.RequiredArgsConstructor;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Service;
import ru.edu.mirea.pppeis.storage.group.model.GroupPg;
import ru.edu.mirea.pppeis.storage.student.dao.StudentNeoDao;
import ru.edu.mirea.pppeis.storage.student.dao.StudentPgDao;
import ru.edu.mirea.pppeis.storage.student.dao.StudentRedisDao;
import ru.edu.mirea.pppeis.storage.student.model.StudentNeo;
import ru.edu.mirea.pppeis.storage.student.model.StudentPg;
import ru.edu.mirea.pppeis.storage.student.model.StudentRedis;

import java.util.Date;
import java.util.List;
import java.util.Optional;
import java.util.UUID;

import static com.google.common.collect.Lists.newArrayList;
import static java.time.ZoneId.systemDefault;

@Service
@RequiredArgsConstructor
public class StudentService {

    private final StudentPgDao studentPgDao;
    private final StudentNeoDao studentNeoDao;
    private final StudentRedisDao studentRedisDao;

    @NonNull
    public StudentPg createPg(@NonNull StudentPg student, @NonNull GroupPg group) {
        student.setId(UUID.randomUUID().toString());
        student.setGroup(group);
        return studentPgDao.save(student);
    }

    @NonNull
    public StudentNeo createNeo(@NonNull String id) {
        return studentNeoDao.save(new StudentNeo().setId(id));
    }

    @NonNull
    public StudentRedis createRedis(@NonNull StudentPg student,
                                    @NonNull String groupId,
                                    double attendancePercentage) {
        var studentRedis = new StudentRedis()
                .setId(student.getId())
                .setPgId(student.getId())
                .setFirstName(student.getFirstName())
                .setLastName(student.getLastName())
                .setMiddleName(student.getMiddleName())
                .setBirthDate(new Date(student.getBirthDate().getTime())
                        .toInstant()
                        .atZone(systemDefault())
                        .toLocalDate())
                .setGender(student.getGender())
                .setGroupId(groupId)
                .setAttendancePercent(attendancePercentage);
        return studentRedisDao.save(studentRedis);
    }

    public Optional<StudentRedis> findByIdRedis(@NonNull String id) {
        return studentRedisDao.findById(id);
    }

    public List<StudentPg> findAllByGroupIdPg(@NonNull String groupId) {
        return studentPgDao.findAllByGroupId(groupId);
    }

    public List<StudentPg> findAllPg() {
        return newArrayList(studentPgDao.findAll());
    }

    public void deleteByIdRedis(@NonNull String id) {
        studentRedisDao.deleteById(id);
    }

}
