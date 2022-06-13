package org.dev.safe.software.threads.configuration;

import lombok.RequiredArgsConstructor;
import org.dev.safe.software.threads.configuration.properties.ThreadsCountProperties;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import java.util.concurrent.LinkedBlockingDeque;
import java.util.concurrent.ThreadPoolExecutor;

import static java.util.concurrent.TimeUnit.SECONDS;

@Configuration
@RequiredArgsConstructor
public class ThreadPoolConfiguration {

    private final ThreadsCountProperties properties;

    @Bean("taskThreadPoolExecutor")
    public ThreadPoolExecutor threadPoolExecutor() {
        return new ThreadPoolExecutor(
                properties.getCoreThreads(),
                properties.getMaxThreads(),
                properties.getKeepAlive().getSeconds(),
                SECONDS,
                new LinkedBlockingDeque<>(properties.getQueueSize())
        );
    }

}
