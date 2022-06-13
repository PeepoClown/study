package org.dev.safe.software.files.operation.json.model;

import lombok.Data;

import java.io.Serializable;

@Data
public class SubSerializableObject
        implements Serializable {
    private static final long serialVersionUID = -2537374293604345802L;
    private String data;
}
