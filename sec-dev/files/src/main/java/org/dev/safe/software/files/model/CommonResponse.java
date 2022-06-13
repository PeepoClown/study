package org.dev.safe.software.files.model;

import lombok.Getter;
import lombok.experimental.SuperBuilder;
import org.springframework.http.HttpStatus;

@Getter
@SuperBuilder
public abstract class CommonResponse {
    private final HttpStatus statusCode;

    public abstract boolean isSuccess();

}
