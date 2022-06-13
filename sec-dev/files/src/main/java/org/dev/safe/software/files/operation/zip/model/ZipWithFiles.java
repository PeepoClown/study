package org.dev.safe.software.files.operation.zip.model;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.List;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class ZipWithFiles {
    private String path;
    private List<String> files;
}
