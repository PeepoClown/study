package ru.edu.mirea.pppeis.configuration.properties;

import lombok.Data;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.validation.annotation.Validated;

import javax.validation.constraints.Max;
import javax.validation.constraints.Min;
import javax.validation.constraints.NotBlank;

@Data
@Validated
@ConfigurationProperties("elastic")
public class ElasticProperties {

    @NotBlank
    private String host = "localhost";

    @Min(1024)
    @Max(65535)
    private Integer port = 9200;

}
