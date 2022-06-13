package org.dev.safe.software.files.operation.info.model;

import lombok.Builder;
import lombok.Getter;

@Getter
@Builder
public class InfoOperationResult {
    private final String name;
    private final String path;
    private final Long usedSpace;
    private final Long totalSpace;
    private final String fsType;
}
