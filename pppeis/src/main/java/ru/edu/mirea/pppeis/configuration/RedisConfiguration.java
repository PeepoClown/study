package ru.edu.mirea.pppeis.configuration;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.data.redis.connection.jedis.JedisConnectionFactory;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.data.redis.repository.configuration.EnableRedisRepositories;
import org.springframework.data.redis.serializer.GenericToStringSerializer;
import ru.edu.mirea.pppeis.storage.student.model.StudentRedis;

@Configuration
@EnableRedisRepositories("ru.edu.mirea.pppeis.storage")
public class RedisConfiguration {

    @Bean
    public JedisConnectionFactory jedisConnectionFactory() {
        return new JedisConnectionFactory();
    }

    @Bean
    public RedisTemplate<String, StudentRedis> redisTemplate() {
        var redisTemplate = new RedisTemplate<String, StudentRedis>();
        redisTemplate.setConnectionFactory(jedisConnectionFactory());
        redisTemplate.setValueSerializer(new GenericToStringSerializer<>(StudentRedis.class));
        return redisTemplate;
    }

}
