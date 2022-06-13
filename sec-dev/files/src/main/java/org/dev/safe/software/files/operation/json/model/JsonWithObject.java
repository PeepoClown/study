package org.dev.safe.software.files.operation.json.model;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class JsonWithObject {
    private String path;
    private SerializableObject object;
}
