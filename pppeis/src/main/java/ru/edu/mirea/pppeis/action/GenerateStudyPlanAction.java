package ru.edu.mirea.pppeis.action;

import com.fasterxml.jackson.core.type.TypeReference;
import com.fasterxml.jackson.databind.ObjectMapper;
import lombok.RequiredArgsConstructor;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Service;
import ru.edu.mirea.pppeis.storage.course.CourseService;
import ru.edu.mirea.pppeis.storage.course.model.CoursePg;
import ru.edu.mirea.pppeis.storage.direction.DirectionService;
import ru.edu.mirea.pppeis.storage.direction.model.DirectionPg;
import ru.edu.mirea.pppeis.storage.subject.SubjectService;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import static java.util.stream.Collectors.toList;

@Service
@RequiredArgsConstructor
public class GenerateStudyPlanAction {

    private final ObjectMapper objectMapper;
    private final CourseService courseService;
    private final SubjectService subjectService;
    private final DirectionService directionService;

    public void generate() {
        var studyPlan = getStudyPlan();
        var savedCourses = studyPlan
                .stream()
                .map(courseService::createPg)
                .collect(toList());

        for (int i = 0; i < studyPlan.size(); i++) {
            for (int j = 0; j < studyPlan.get(i).getSubjects().size(); j++) {
                subjectService.createPg(studyPlan.get(i).getSubjects().get(j), savedCourses.get(i));
            }
        }
        generateDirections(savedCourses);
    }

    private void generateDirections(@NonNull List<CoursePg> savedCourses) {
        var directions = getDirections();
        var savedDirections = directions
                .stream()
                .map(direction -> directionService.createPg(direction,
                        getCoursesByName(direction.getCourses().stream().map(CoursePg::getName).collect(toList()))))
                .collect(toList());

        savedCourses.forEach(course -> courseService.updateDirectionByNamePg(course.getName(),
                getDirectionsRelatedToCourse(course.getName(), savedDirections)));
    }

    private List<CoursePg> getStudyPlan() {
        final String studyPlanResource = "/initdata/study_plan.json";
        var parsedData = new ArrayList<CoursePg>();
        try {
            parsedData = objectMapper.readValue(GenerateStudyPlanAction.class.getResourceAsStream(studyPlanResource),
                    new TypeReference<>() { });
        } catch (IOException e) {
            e.printStackTrace();
        }

        return parsedData;
    }

    public List<DirectionPg> getDirections() {
        final String directionsResource = "/initdata/directions.json";
        var parsedData = new ArrayList<DirectionPg>();
        try {
            parsedData = objectMapper.readValue(GenerateStudyPlanAction.class.getResourceAsStream(directionsResource),
                    new TypeReference<>() { });
        } catch (IOException e) {
            e.printStackTrace();
        }

        return parsedData;
    }

    private List<CoursePg> getCoursesByName(@NonNull List<String> names) {
        var courses = new ArrayList<CoursePg>();
        for (var name : names) {
            var course = courseService.findByNamePg(name);
            course.ifPresent(courses::add);
        }
        return courses;
    }

    private List<DirectionPg> getDirectionsRelatedToCourse(@NonNull String name, @NonNull List<DirectionPg> directions) {
        var resultDirections = new ArrayList<DirectionPg>();
        for (var direction : directions) {
            var courses = direction.getCourses();
            boolean isRelated = false;
            for (var course : courses) {
                if (course.getName().equals(name)) {
                    isRelated = true;
                    break;
                }
            }
            if (isRelated) {
                resultDirections.add(direction);
            }
        }
        return resultDirections;
    }

}
