package ru.edu.mirea.pppeis.api.v1;

import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import ru.edu.mirea.pppeis.action.CalcAttendanceQueryAction;
import ru.edu.mirea.pppeis.api.v1.model.AttendanceQueryRequest;
import ru.edu.mirea.pppeis.api.v1.model.AttendanceQueryResponse;

import static org.springframework.http.HttpStatus.INTERNAL_SERVER_ERROR;
import static org.springframework.http.HttpStatus.OK;

@Slf4j
@RestController
@RequiredArgsConstructor
@RequestMapping("/api/v1/query")
public class QueryController {

    private final CalcAttendanceQueryAction calcAttendanceQueryAction;

    @GetMapping("/attendance")
    public AttendanceQueryResponse getAttendanceStatistics(@RequestBody AttendanceQueryRequest request) {
        try {
            return calcAttendanceQueryAction.process(request)
                    .setStatusCode(OK.getReasonPhrase());
        } catch (Exception e) {
            log.error("Failed to get attendance percentage of students. {}", e.getMessage(), e);
            return new AttendanceQueryResponse()
                    .setFromDate(request.getFromDate())
                    .setToDate(request.getToDate())
                    .setLessonTextKeyword(request.getLessonTextKeyword())
                    .setStatusCode(INTERNAL_SERVER_ERROR.getReasonPhrase())
                    .setStatusDescription(e.getMessage());
        }
    }

}
