package org.dev.safe.software.files.util;

import org.dev.safe.software.files.model.FailResponse;
import org.springframework.lang.NonNull;

import static org.springframework.http.HttpStatus.INTERNAL_SERVER_ERROR;

public class BuildUtils {

    @NonNull
    public static FailResponse buildFailResponse(@NonNull Throwable e) {
        return FailResponse.builder()
                .statusCode(INTERNAL_SERVER_ERROR)
                .errorMessage(e.getMessage())
                .exception(e)
                .build();
    }

}
