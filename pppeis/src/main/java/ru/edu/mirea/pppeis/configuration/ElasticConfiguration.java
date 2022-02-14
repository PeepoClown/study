package ru.edu.mirea.pppeis.configuration;

import lombok.RequiredArgsConstructor;
import org.elasticsearch.client.RestHighLevelClient;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.data.elasticsearch.client.ClientConfiguration;
import org.springframework.data.elasticsearch.client.RestClients;
import org.springframework.data.elasticsearch.core.ElasticsearchOperations;
import org.springframework.data.elasticsearch.core.ElasticsearchRestTemplate;
import org.springframework.data.elasticsearch.repository.config.EnableElasticsearchRepositories;
import ru.edu.mirea.pppeis.configuration.properties.ElasticProperties;

import static java.lang.String.format;

@Configuration
@RequiredArgsConstructor
@EnableElasticsearchRepositories("ru.edu.mirea.pppeis.storage")
public class ElasticConfiguration {

    private final ElasticProperties elasticProperties;

    @Bean
    public RestHighLevelClient elasticRestClient() {
        var client = ClientConfiguration.builder()
                .connectedTo(format("%s:%d", elasticProperties.getHost(), elasticProperties.getPort()))
                .build();

        return RestClients.create(client).rest();
    }

    @Bean
    public ElasticsearchOperations elasticsearchTemplate() {
        return new ElasticsearchRestTemplate(elasticRestClient());
    }

}
