package org.dev.safe.software.files.api;

import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.dev.safe.software.files.model.CommonResponse;
import org.dev.safe.software.files.operation.file.FileOperationService;
import org.dev.safe.software.files.operation.file.model.FileWithDataModel;
import org.dev.safe.software.files.operation.file.model.FileWithPathModel;
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
        path = "api/public/v1/files",
        consumes = APPLICATION_JSON_VALUE,
        produces = APPLICATION_JSON_VALUE)
public class FilesController {

    private final FileOperationService fileOperationService;

    @PostMapping
    public CommonResponse create(@RequestBody FileWithPathModel request) {
        log.debug("Received create file request. {}", request);
        var response = fileOperationService.createFile(request.getPath());
        log.debug("Return create file response. {}", response);
        return response;
    }

    @GetMapping
    public CommonResponse readByPath(@RequestParam(required = true) String path) {
        log.debug("Received read file request. {}", path);
        var response = fileOperationService.readFile(path);
        log.debug("Return read file response. {}", response);
        return response;
    }

    @PutMapping
    public CommonResponse write(@RequestBody FileWithDataModel request) {
        log.debug("Received write file request. {}", request);
        var response = fileOperationService.writeFile(request.getPath(), request.getData());
        log.debug("Return write file response. {}", response);
        return response;
    }

    @DeleteMapping
    public CommonResponse delete(@RequestBody FileWithPathModel request) {
        log.debug("Received delete file request. {}", request);
        var response = fileOperationService.deleteFile(request.getPath());
        log.debug("Return delete file response. {}", response);
        return response;
    }

}
