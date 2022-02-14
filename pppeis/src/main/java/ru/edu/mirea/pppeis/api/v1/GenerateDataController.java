package ru.edu.mirea.pppeis.api.v1;

import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import ru.edu.mirea.pppeis.action.AddAttendanceQueryDataAction;
import ru.edu.mirea.pppeis.action.GenerateScheduleAction;
import ru.edu.mirea.pppeis.action.GenerateStudentsAction;
import ru.edu.mirea.pppeis.action.GenerateStudyPlanAction;
import ru.edu.mirea.pppeis.configuration.properties.GenerationProperties;

import static org.springframework.http.ResponseEntity.internalServerError;
import static org.springframework.http.ResponseEntity.ok;

@Slf4j
@RestController
@RequiredArgsConstructor
@RequestMapping("/api/v1/generate")
public class GenerateDataController {

    private final GenerationProperties generationProperties;
    private final GenerateStudentsAction generateStudentsAction;
    private final GenerateScheduleAction generateScheduleAction;
    private final GenerateStudyPlanAction generateStudyPlanAction;
    private final AddAttendanceQueryDataAction addAttendanceQueryDataAction;

    @PostMapping("/studyplan")
    public ResponseEntity<?> generateStudyPlan() {
        try {
            if (generationProperties.getStudyPlan()) {
                generateStudyPlanAction.generate();
                log.info("Subjects, courses and directions - generated");
            }
            return ok().build();
        } catch (Exception e) {
            log.error("Failed to generate study plan. {}", e.getMessage(), e);
            return internalServerError().build();
        }
    }

    @PostMapping("/students")
    public ResponseEntity<?> generateStudents() {
        try {
            if (generationProperties.getStudents()) {
                generateStudentsAction.generate();
                log.info("Students and groups - generated");
            }
            return ok().build();
        } catch (Exception e) {
            log.error("Failed to generate students. {}", e.getMessage(), e);
            return internalServerError().build();
        }
    }

    @PostMapping("/schedule")
    public ResponseEntity<?> generateSchedule() {
        try {
            if (generationProperties.getSchedule()) {
                generateScheduleAction.generate();
                log.info("Schedule - generated");
            }
            return ok().build();
        } catch (Exception e) {
            log.error("Failed to generate schedule. {}", e.getMessage(), e);
            return internalServerError().build();
        }
    }

    @PostMapping("/attendance")
    public ResponseEntity<?> generateAttendance() {
        try {
            if (generationProperties.getAttendance()) {
                addAttendanceQueryDataAction.generate();
                log.info("Neo schema - generated");
            }
            return ok().build();
        } catch (Exception e) {
            log.error("Failed to generate neo schema. {}", e.getMessage(), e);
            return internalServerError().build();
        }
    }

    @PostMapping
    public ResponseEntity<?> generateAll() {
        try {
            generateStudyPlan();
            generateStudents();
            generateSchedule();
            generateAttendance();
            return ok().build();
        } catch (Exception e) {
            log.error("Failed to generate schema. {}", e.getMessage(), e);
            return internalServerError().build();
        }
    }

}
