package ru.edu.mirea.pppeis.storage.group;

import lombok.RequiredArgsConstructor;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Service;
import ru.edu.mirea.pppeis.storage.direction.model.DirectionPg;
import ru.edu.mirea.pppeis.storage.group.dao.GroupNeoDao;
import ru.edu.mirea.pppeis.storage.group.dao.GroupPgDao;
import ru.edu.mirea.pppeis.storage.group.model.GroupNeo;
import ru.edu.mirea.pppeis.storage.group.model.GroupPg;
import ru.edu.mirea.pppeis.storage.student.model.StudentNeo;
import ru.edu.mirea.pppeis.storage.student.model.StudentPg;

import java.util.List;
import java.util.Optional;
import java.util.UUID;

@Service
@RequiredArgsConstructor
public class GroupService {

    private final GroupPgDao groupPgDao;
    private final GroupNeoDao groupNeoDao;

    @NonNull
    public GroupPg createPg(@NonNull GroupPg group, @NonNull DirectionPg direction) {
        group.setId(UUID.randomUUID().toString());
        group.setDirection(direction);
        return groupPgDao.save(group);
    }

    @NonNull
    public GroupNeo createNeo(@NonNull GroupNeo groupNeo, @NonNull List<StudentNeo> students) {
        groupNeo.setStudents(students);
        return groupNeoDao.save(groupNeo);
    }

    public Optional<GroupPg> findByNamePg(@NonNull String name) {
        return groupPgDao.findByName(name);
    }

    public List<GroupPg> findAllByDirectionId(@NonNull String directionId) {
        return groupPgDao.findAllByDirectionId(directionId);
    }

    public void updateLeadByNamePg(@NonNull String name, @NonNull StudentPg lead) {
        var group = findByNamePg(name);
        if (group.isPresent()) {
            group.get().setGroupLead(lead);
            groupPgDao.save(group.get());
        }
    }

}
