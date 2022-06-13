package org.dev.safe.software.threads.configuration.properties;

import lombok.Data;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.validation.annotation.Validated;

import javax.validation.constraints.Max;
import javax.validation.constraints.Min;
import javax.validation.constraints.NotNull;
import java.time.Duration;

import static java.time.Duration.ofSeconds;

@Data
@Validated
@ConfigurationProperties("pool")
public class ThreadsCountProperties {

    @Min(1)
    @Max(26)
    private Integer coreThreads;

    @Min(1)
    @Max(26)
    private Integer maxThreads;

    private Duration keepAlive = ofSeconds(10);

    @NotNull
    private Integer queueSize;

}
