package org.dev.safe.software.files.api;

import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.dev.safe.software.files.operation.info.InfoOperationService;
import org.dev.safe.software.files.operation.info.model.InfoOperationResult;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

import static org.springframework.util.MimeTypeUtils.APPLICATION_JSON_VALUE;

@Slf4j
@RestController
@RequiredArgsConstructor
@RequestMapping(
        path = "api/public/v1/info",
        consumes = APPLICATION_JSON_VALUE,
        produces = APPLICATION_JSON_VALUE)
public class InfoController {

    private final InfoOperationService infoOperationService;

    @GetMapping
    public List<InfoOperationResult> getInfo() {
        log.debug("Received get info request");
        var response = infoOperationService.getDrivesInfo();
        log.debug("Return get info response. {}", response);
        return response;
    }

}
