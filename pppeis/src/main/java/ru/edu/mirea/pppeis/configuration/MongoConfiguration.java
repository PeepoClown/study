package ru.edu.mirea.pppeis.configuration;

import org.springframework.context.annotation.Configuration;
import org.springframework.data.mongodb.repository.config.EnableMongoRepositories;

@Configuration
@EnableMongoRepositories("ru.edu.mirea.pppeis.storage")
public class MongoConfiguration { }
