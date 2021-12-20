package org.dev.safe.software.files.model;

import lombok.Getter;
import lombok.experimental.SuperBuilder;

@Getter
@SuperBuilder
public class FailResponse
        extends CommonResponse {
    private final String errorMessage;
    private final Throwable exception;

    public boolean isSuccess() {
        return false;
    }
}
