package ru.edu.mirea.pppeis.configuration.properties;

import lombok.Data;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.validation.annotation.Validated;

import javax.validation.constraints.NotNull;

@Data
@Validated
@ConfigurationProperties("generation")
public class GenerationProperties {

    @NotNull
    private Boolean studyPlan;

    @NotNull
    private Boolean students;

    @NotNull
    private Boolean schedule;

    @NotNull
    private Boolean attendance;

}
