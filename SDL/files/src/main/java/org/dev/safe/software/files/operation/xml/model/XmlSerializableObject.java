package org.dev.safe.software.files.operation.xml.model;


import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlAttribute;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;
import java.io.Serializable;
import java.math.BigDecimal;

@Data
@NoArgsConstructor
@AllArgsConstructor
@XmlRootElement(name = "object")
@XmlAccessorType(XmlAccessType.FIELD)
public class XmlSerializableObject
        implements Serializable {
    private static final long serialVersionUID = -7711629977317306513L;
    @XmlAttribute(name = "id")
    private String id;
    @XmlElement(name = "description")
    private String description;
    @XmlElement(name = "price")
    private BigDecimal price;
}
