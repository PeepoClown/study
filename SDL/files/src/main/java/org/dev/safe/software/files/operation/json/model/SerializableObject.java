package org.dev.safe.software.files.operation.json.model;

import lombok.Data;

import java.io.Serializable;

@Data
public class SerializableObject
        implements Serializable {
    private static final long serialVersionUID = 6269591427458900873L;
    private String filedStr;
    private int fieldInt;
    private boolean filedBool;
    private SubSerializableObject filedSubObject;
}
