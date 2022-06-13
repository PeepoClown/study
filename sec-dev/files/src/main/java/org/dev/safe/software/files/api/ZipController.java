package org.dev.safe.software.files.api;

import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.dev.safe.software.files.model.CommonResponse;
import org.dev.safe.software.files.operation.zip.ZipOperationService;
import org.dev.safe.software.files.operation.zip.model.ZipWithDest;
import org.dev.safe.software.files.operation.zip.model.ZipWithFiles;
import org.dev.safe.software.files.operation.zip.model.ZipWithPath;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import static org.springframework.util.MimeTypeUtils.APPLICATION_JSON_VALUE;

@Slf4j
@RestController
@RequiredArgsConstructor
@RequestMapping(
        path = "api/public/v1/zips",
        consumes = APPLICATION_JSON_VALUE,
        produces = APPLICATION_JSON_VALUE)
public class ZipController {

    private final ZipOperationService zipOperationService;

    @PostMapping
    public CommonResponse create(@RequestBody ZipWithFiles request) {
        log.debug("Received create zip archive request. '{}'", request);
        var response = zipOperationService.create(request.getPath(), request.getFiles());
        log.debug("Returned create zip archive response. '{}'", response);
        return response;
    }

    @GetMapping
    public CommonResponse unzip(@RequestBody ZipWithDest request) {
        log.debug("Received unzip archive request. '{}'", request);
        var response = zipOperationService.unzipArchive(request.getPath(), request.getDestination());
        log.debug("Returned unzip archive response. '{}'", response);
        return response;
    }

    @PutMapping
    public CommonResponse addFile(@RequestBody ZipWithFiles request) {
        log.debug("Received add file to zip archive request. '{}'", request);
        var response = zipOperationService.addFileToArchive(request.getPath(), request.getFiles());
        log.debug("Returned add file to zip archive response. '{}'", response);
        return response;
    }

    @DeleteMapping
    public CommonResponse delete(@RequestBody ZipWithPath request) {
        log.debug("Received delete zip archive request. '{}'", request);
        var response = zipOperationService.deleteArchive(request.getPath());
        log.debug("Returned delete zip archive response. '{}'", response);
        return response;
    }

}
