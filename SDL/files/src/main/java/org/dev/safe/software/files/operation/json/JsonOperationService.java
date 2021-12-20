package org.dev.safe.software.files.operation.json;

import com.fasterxml.jackson.databind.ObjectMapper;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.dev.safe.software.files.model.CommonResponse;
import org.dev.safe.software.files.model.SuccessResponse;
import org.dev.safe.software.files.operation.file.FileOperationService;
import org.dev.safe.software.files.operation.json.model.SerializableObject;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Service;

import java.io.File;
import java.io.IOException;

import static org.dev.safe.software.files.util.BuildUtils.buildFailResponse;

@Slf4j
@Service
@RequiredArgsConstructor
public class JsonOperationService {

    private final ObjectMapper objectMapper;
    private final FileOperationService fileOperationService;

    @NonNull
    public CommonResponse createJson(@NonNull String path, @NonNull String data) {
        var creationResult = fileOperationService.createFile(path);
        if (!creationResult.isSuccess()) {
            return creationResult;
        }

        return fileOperationService.writeFile(path, data);
    }

    @NonNull
    public CommonResponse writeObjectToJson(@NonNull String path, @NonNull SerializableObject object) {
        try {
            var creationResult = fileOperationService.createFile(path);
            if (!creationResult.isSuccess()) {
                return creationResult;
            }

            objectMapper.writeValue(((SuccessResponse<File>) creationResult).getData(), object);

            log.info("Success to serialize '{}' to json and write it into '{}", object, path);
            return fileOperationService.readFile(path);
        } catch (IOException e) {
            log.error("Failed to write serialized object to json. '{}'", e.getMessage(), e);
            return buildFailResponse(e);
        }
    }

    @NonNull
    public CommonResponse readJson(@NonNull String path) {
        return fileOperationService.readFile(path);
    }

    @NonNull
    public CommonResponse deleteJson(@NonNull String path) {
        return fileOperationService.deleteFile(path);
    }


}
