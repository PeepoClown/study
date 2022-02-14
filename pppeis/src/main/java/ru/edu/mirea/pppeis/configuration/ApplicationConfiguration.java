package ru.edu.mirea.pppeis.configuration;

import org.springframework.boot.context.properties.EnableConfigurationProperties;
import org.springframework.context.annotation.Configuration;
import ru.edu.mirea.pppeis.configuration.properties.ElasticProperties;
import ru.edu.mirea.pppeis.configuration.properties.GenerationProperties;

@Configuration
@EnableConfigurationProperties({
        ElasticProperties.class,
        GenerationProperties.class
})
public class ApplicationConfiguration { }
