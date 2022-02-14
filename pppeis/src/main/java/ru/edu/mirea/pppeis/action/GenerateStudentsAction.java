package ru.edu.mirea.pppeis.action;

import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.node.ArrayNode;
import com.google.common.collect.Streams;
import lombok.RequiredArgsConstructor;
import org.apache.commons.lang3.tuple.ImmutablePair;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Service;
import ru.edu.mirea.pppeis.storage.direction.DirectionService;
import ru.edu.mirea.pppeis.storage.group.GroupService;
import ru.edu.mirea.pppeis.storage.group.model.GroupPg;
import ru.edu.mirea.pppeis.storage.student.StudentService;
import ru.edu.mirea.pppeis.storage.student.model.Gender;
import ru.edu.mirea.pppeis.storage.student.model.StudentPg;

import java.io.IOException;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.stream.Collectors;

import static com.google.common.collect.Lists.partition;
import static java.time.LocalDate.ofEpochDay;
import static java.time.ZoneId.systemDefault;
import static java.util.concurrent.ThreadLocalRandom.current;
import static ru.edu.mirea.pppeis.storage.student.model.Gender.FEMALE;
import static ru.edu.mirea.pppeis.storage.student.model.Gender.MALE;

@Service
@RequiredArgsConstructor
public class GenerateStudentsAction {

    private final ObjectMapper objectMapper;
    private final GroupService groupService;
    private final StudentService studentService;
    private final DirectionService directionService;
    private final GenerateStudyPlanAction generateStudyPlanAction;

    public void generate() {
        var students = geStudents();
        var groups = getGroups();
        generateGroups(students, groups);
    }

    private void generateGroups(@NonNull ImmutablePair<List<StudentPg>, List<StudentPg>> studentsPair,
                                @NonNull List<GroupPg> groupList) {
        var directions = generateStudyPlanAction.getDirections();
        List<List<StudentPg>> maleByGroups = partition(studentsPair.left, studentsPair.left.size() / groupList.size());
        List<List<StudentPg>> femaleByGroups = partition(studentsPair.right, studentsPair.right.size() / groupList.size());

        for (int i = 0; i < groupList.size(); i++) {
            var group = groupList.get(i);
            groupService.createPg(group, directionService.findByNamePg(directions.get(i % 2).getName()).get());
            List<StudentPg> studentsByGroup = Streams.concat(maleByGroups.get(i).stream(), femaleByGroups.get(i).stream())
                    .collect(Collectors.toList());
            studentsByGroup.forEach(student -> studentService.createPg(student, group));
            var lead = studentsByGroup.get(current().nextInt(studentsByGroup.size()));
            groupService.updateLeadByNamePg(group.getName(), lead);
        }
    }

    private ImmutablePair<List<StudentPg>, List<StudentPg>> geStudents() {
        final String directionsResource = "/initdata/students_groups.json";
        var maleStudents = new ArrayList<StudentPg>();
        var femaleStudents = new ArrayList<StudentPg>();

        try {
            var node = objectMapper.readTree(GenerateStudyPlanAction.class.getResourceAsStream(directionsResource));
            maleStudents.addAll(createStudentsListByGender((ArrayNode) node.get("male"), MALE));
            femaleStudents.addAll(createStudentsListByGender((ArrayNode) node.get("female"), FEMALE));
        } catch (IOException e) {
            e.printStackTrace();
        }

        return ImmutablePair.of(maleStudents, femaleStudents);
    }

    private List<StudentPg> createStudentsListByGender(@NonNull ArrayNode node, @NonNull Gender gender) {
        var students = new ArrayList<StudentPg>();
        final long beginBirthDate = LocalDate.parse("1995-01-01").toEpochDay();
        final long endBirthDate = LocalDate.parse("2005-01-01").toEpochDay();

        for (var student : node) {
            var name = student.toString()
                    .substring(1, student.toString().length() - 1).split(" ");
            students.add(new StudentPg()
                    .setFirstName(name[1])
                    .setLastName(name[0])
                    .setMiddleName(name[2])
                    .setBirthDate(getRandomDateInRange(beginBirthDate, endBirthDate))
                    .setGender(gender));
        }

        return students;
    }

    private List<GroupPg> getGroups() {
        final String directionsResource = "/initdata/students_groups.json";
        var groups = new ArrayList<GroupPg>();

        try {
            var node = objectMapper.readTree(GenerateStudyPlanAction.class.getResourceAsStream(directionsResource));
            var groupsNode = (ArrayNode) node.get("groups");
            for (var group : groupsNode) {
                groups.add(objectMapper.treeToValue(group, GroupPg.class));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        return groups;
    }

    @NonNull
    public static Date getRandomDateInRange(long min, long max) {
        return Date.from(ofEpochDay(current().nextLong(min, max))
                .atStartOfDay()
                .atZone(systemDefault())
                .toInstant());
    }


}
