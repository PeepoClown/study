package org.dev.safe.software.files.api;

import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.dev.safe.software.files.model.CommonResponse;
import org.dev.safe.software.files.operation.file.model.FileWithDataModel;
import org.dev.safe.software.files.operation.file.model.FileWithPathModel;
import org.dev.safe.software.files.operation.json.JsonOperationService;
import org.dev.safe.software.files.operation.json.model.JsonWithObject;
import org.dev.safe.software.files.operation.xml.XmlOperationService;
import org.dev.safe.software.files.operation.xml.model.XmlWithObject;
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
        path = "api/public/v1/xmls",
        consumes = APPLICATION_JSON_VALUE,
        produces = APPLICATION_JSON_VALUE)
public class XmlController {

    private final XmlOperationService xmlOperationService;

    @PostMapping
    public CommonResponse create(@RequestBody FileWithDataModel request) {
        log.debug("Received create xml request. {}", request);
        var response = xmlOperationService.createXml(request.getPath(), request.getData());
        log.debug("Return create xml response. {}", response);
        return response;
    }

    @GetMapping
    public CommonResponse readByPath(@RequestParam(required = true) String path) {
        log.debug("Received read xml request. {}", path);
        var response = xmlOperationService.readXml(path);
        log.debug("Return read xml response. {}", response);
        return response;
    }

    @PutMapping
    public CommonResponse write(@RequestBody XmlWithObject request) {
        log.debug("Received write xml request. {}", request);
        var response = xmlOperationService.writeObjectToXml(request.getPath(), request.getObject());
        log.debug("Return write xml response. {}", response);
        return response;
    }

    @DeleteMapping
    public CommonResponse delete(@RequestBody FileWithPathModel request) {
        log.debug("Received delete xml request. {}", request);
        var response = xmlOperationService.deleteXml(request.getPath());
        log.debug("Return delete xml response. {}", response);
        return response;
    }

}
