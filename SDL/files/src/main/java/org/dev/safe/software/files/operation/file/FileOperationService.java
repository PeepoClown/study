package org.dev.safe.software.files.operation.file;

import lombok.extern.slf4j.Slf4j;
import org.dev.safe.software.files.model.CommonResponse;
import org.dev.safe.software.files.model.SuccessResponse;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Service;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;

import static java.nio.charset.StandardCharsets.UTF_8;
import static org.dev.safe.software.files.util.BuildUtils.buildFailResponse;
import static org.springframework.http.HttpStatus.OK;

@Slf4j
@Service
public class FileOperationService {

    @NonNull
    public CommonResponse createFile(@NonNull String path) {
        try {
            var file = new File(path);
            if (file.createNewFile()) {
                log.info("File '{}' successfully created", path);
            } else {
                log.info("File '{}' already exists", path);
            }
            return SuccessResponse.builder()
                    .statusCode(OK)
                    .data(file)
                    .build();
        } catch (IOException e) {
            log.error("Failed to create file. '{}'", e.getMessage(), e);
            return buildFailResponse(e);
        }
    }

    @NonNull
    public CommonResponse deleteFile(@NonNull String path) {
        try {
            var file = new File(path);
            if (file.delete()) {
                log.info("File '{}' successfully deleted", path);
            } else {
                log.info("File '{}' not exists", path);
            }
            return SuccessResponse.builder()
                    .statusCode(OK)
                    .build();
        } catch (Exception e) {
            log.error("Failed to deleted file. '{}'", e.getMessage(), e);
            return buildFailResponse(e);
        }
    }

    @NonNull
    public CommonResponse readFile(@NonNull String path) {
        try (var bufferedReader = new BufferedReader(new InputStreamReader(new FileInputStream(path)))) {
            var sb = new StringBuilder();
            String line = null;

            log.info("Success to read file '{}'. Content:", path);
            while ((line = bufferedReader.readLine()) != null) {
                sb.append(line).append('\n');
            }

            return SuccessResponse.builder()
                    .statusCode(OK)
                    .data(sb.toString())
                    .build();
        } catch (IOException e) {
            log.error("Failed to read file. '{}'", e.getMessage(), e);
            return buildFailResponse(e);
        }
    }

    @NonNull
    public CommonResponse writeFile(@NonNull String path, @NonNull String data) {
        try (var outputStream = new FileOutputStream(path)) {
            byte[] strToBytes = data.getBytes(UTF_8);
            outputStream.write(strToBytes);
            log.info("Successfully write to file '{}'", path);

            return SuccessResponse.builder()
                    .statusCode(OK)
                    .build();
        } catch (IOException e) {
            log.error("Failed to write to file. '{}'", e.getMessage(), e);
            return buildFailResponse(e);
        }
    }

}
