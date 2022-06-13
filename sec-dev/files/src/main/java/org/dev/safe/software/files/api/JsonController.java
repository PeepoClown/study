package org.dev.safe.software.files.api;

import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.dev.safe.software.files.model.CommonResponse;
import org.dev.safe.software.files.operation.file.model.FileWithDataModel;
import org.dev.safe.software.files.operation.file.model.FileWithPathModel;
import org.dev.safe.software.files.operation.json.JsonOperationService;
import org.dev.safe.software.files.operation.json.model.JsonWithObject;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import static org.springframework.util.MimeTypeUtils.APPLICATION_JSON_VALUE;

@Slf4j
@RestController
@RequiredArgsConstructor
@RequestMapping(
        path = "api/public/v1/jsons",
        consumes = APPLICATION_JSON_VALUE,
        produces = APPLICATION_JSON_VALUE)
public class JsonController {

    private final JsonOperationService jsonOperationService;

    @PostMapping
    public CommonResponse create(@RequestBody FileWithDataModel request) {
        log.debug("Received create json request. {}", request);
        var response = jsonOperationService.createJson(request.getPath(), request.getData());
        log.debug("Return create json response. {}", response);
        return response;
    }

    @GetMapping
    public CommonResponse readByPath(@RequestParam(required = true) String path) {
        log.debug("Received read json request. {}", path);
        var response = jsonOperationService.readJson(path);
        log.debug("Return read json response. {}", response);
        return response;
    }

    @PutMapping
    public CommonResponse write(@RequestBody JsonWithObject request) {
        log.debug("Received write json request. {}", request);
        var response = jsonOperationService.writeObjectToJson(request.getPath(), request.getObject());
        log.debug("Return write json response. {}", response);
        return response;
    }

    @DeleteMapping
    public CommonResponse delete(@RequestBody FileWithPathModel request) {
        log.debug("Received delete json request. {}", request);
        var response = jsonOperationService.deleteJson(request.getPath());
        log.debug("Return delete json response. {}", response);
        return response;
    }

}
