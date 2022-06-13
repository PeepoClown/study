package org.dev.safe.software.files.operation.zip;

import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import net.lingala.zip4j.core.ZipFile;
import net.lingala.zip4j.exception.ZipException;
import net.lingala.zip4j.model.ZipParameters;
import org.dev.safe.software.files.model.CommonResponse;
import org.dev.safe.software.files.model.SuccessResponse;
import org.dev.safe.software.files.operation.file.FileOperationService;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Service;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;
import java.util.zip.ZipEntry;
import java.util.zip.ZipOutputStream;

import static org.dev.safe.software.files.util.BuildUtils.buildFailResponse;
import static org.springframework.http.HttpStatus.OK;

@Slf4j
@Service
@RequiredArgsConstructor
public class ZipOperationService {

    private final FileOperationService fileOperationService;

    @NonNull
    public CommonResponse create(@NonNull String path, @NonNull List<String> files) {
        var creationResult = fileOperationService.createFile(path);
        if (!creationResult.isSuccess()) {
            return creationResult;
        }
        try (var outputStream = new FileOutputStream(path);
             var zipOutputStream = new ZipOutputStream(outputStream) ) {
            files.forEach(file -> {
                try {
                    File fileToZip = new File(file);
                    FileInputStream fis = new FileInputStream(fileToZip);
                    ZipEntry zipEntry = new ZipEntry(fileToZip.getName());
                    zipOutputStream.putNextEntry(zipEntry);

                    byte[] bytes = new byte[1024];
                    int length;
                    while ((length = fis.read(bytes)) >= 0) {
                        zipOutputStream.write(bytes, 0, length);
                    }
                    fis.close();
                } catch (IOException e) {
                    log.error("Failed to zip archive. '{}'", e.getMessage(), e);
                }
            });

            return SuccessResponse.builder()
                    .statusCode(OK)
                    .build();
        } catch (Exception e) {
            log.error("Failed to zip archive. '{}'", e.getMessage(), e);
            return buildFailResponse(e);
        }
    }

    @NonNull
    public CommonResponse addFileToArchive(@NonNull String path, @NonNull List<String> files) {
        try {
            var zipFile = new ZipFile(path);
            zipFile.addFiles(new ArrayList<>(files
                    .stream()
                    .map(File::new)
                    .collect(Collectors.toList())), new ZipParameters());
            return SuccessResponse.builder()
                    .statusCode(OK)
                    .build();
        } catch (ZipException e) {
            log.error("Failed to add file to archive. '{}'", e.getMessage(), e);
            return buildFailResponse(e);
        }
    }

    @NonNull
    public CommonResponse unzipArchive(@NonNull String path, @NonNull String dest) {
        try {
            var zipFile = new ZipFile(path);
            zipFile.extractAll(dest);

            return SuccessResponse.builder()
                    .statusCode(OK)
                    .build();
        } catch (ZipException e) {
            log.error("Failed to unzip archive. '{}'", e.getMessage(), e);
            return buildFailResponse(e);
        }
    }

    @NonNull
    public CommonResponse deleteArchive(@NonNull String path) {
        return fileOperationService.deleteFile(path);
    }

}
