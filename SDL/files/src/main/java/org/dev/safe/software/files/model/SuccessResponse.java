package org.dev.safe.software.files.model;

import lombok.Getter;
import lombok.experimental.SuperBuilder;

@Getter
@SuperBuilder
public class SuccessResponse<T>
        extends CommonResponse {
    private T data;

    public boolean isSuccess() {
        return true;
    }
}
