package org.dev.safe.software.files.operation.xml.model;

import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@NoArgsConstructor
@AllArgsConstructor
public class XmlWithObject {
    private String path;
    private XmlSerializableObject object;
}
