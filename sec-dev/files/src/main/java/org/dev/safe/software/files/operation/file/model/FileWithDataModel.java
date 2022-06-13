package org.dev.safe.software.files.operation.file.model;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class FileWithDataModel {
    private String path;
    public String data;
}
