package org.dev.safe.software.threads;

import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import java.util.Scanner;
import java.util.concurrent.ThreadPoolExecutor;

import static java.util.Arrays.asList;

@Slf4j
@SpringBootApplication
@RequiredArgsConstructor
public class ThreadsApplication
        implements CommandLineRunner {

    @Qualifier("taskThreadPoolExecutor")
    private final ThreadPoolExecutor threadPoolExecutor;

    public static void main(String[] args) {
        SpringApplication.run(ThreadsApplication.class, args);
    }

    @Override
    public void run(String... args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        String hash1 = scanner.nextLine();
        String hash2 = scanner.nextLine();
        String hash3 = scanner.nextLine();
        var hashes = asList(hash1, hash2, hash3);

        hashes.forEach(hash ->
                threadPoolExecutor.submit(() -> {
                    try {
                        new BruteForce(hash).run();
                    } catch (Exception e) {
                        log.error("Failed to decrypt. '{}'", e.getMessage(), e);
                    }
                })
        );

        threadPoolExecutor.shutdown();
    }

}
