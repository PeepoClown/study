package ru.edu.mirea.pppeis.configuration;

import org.springframework.context.annotation.Configuration;
import org.springframework.data.neo4j.repository.config.EnableNeo4jRepositories;

@Configuration
@EnableNeo4jRepositories("ru.edu.mirea.pppeis.storage")
public class Neo4jConfiguration { }
