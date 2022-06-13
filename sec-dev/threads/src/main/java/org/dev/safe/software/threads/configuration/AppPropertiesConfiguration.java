package org.dev.safe.software.threads.configuration;

import org.dev.safe.software.threads.configuration.properties.ThreadsCountProperties;
import org.springframework.boot.context.properties.EnableConfigurationProperties;
import org.springframework.context.annotation.Configuration;

@Configuration
@EnableConfigurationProperties(ThreadsCountProperties.class)
public class AppPropertiesConfiguration { }
