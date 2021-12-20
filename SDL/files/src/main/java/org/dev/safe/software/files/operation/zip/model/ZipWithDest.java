package org.dev.safe.software.files.operation.zip.model;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class ZipWithDest {
    private String path;
    private String destination;
}
