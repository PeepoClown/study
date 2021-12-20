package org.dev.safe.software.threads;

import lombok.extern.slf4j.Slf4j;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Arrays;

import static java.time.LocalDateTime.now;
import static java.time.temporal.ChronoUnit.MILLIS;
import static javax.xml.bind.DatatypeConverter.parseHexBinary;
import static org.apache.logging.log4j.util.Strings.EMPTY;

@Slf4j
public class BruteForce implements Runnable {
    private static final int LENGTH = 5;

    private final byte[] input;
    private final String inputStr;
    private final MessageDigest digest = MessageDigest.getInstance("SHA-256");

    public BruteForce(String hash) throws NoSuchAlgorithmException {
        inputStr = hash;
        this.input = parseHexBinary(hash);
    }

    @Override
    public void run() {
        String match = EMPTY;
        char[] chars = new char[LENGTH];
        boolean isDone = false;
        var now = now();

        for (chars[0] = 'a'; chars[0] <= 'z' && !isDone; chars[0]++) {
            for (chars[1] = 'a'; chars[1] <= 'z' && !isDone; chars[1]++) {
                for (chars[2] = 'a'; chars[2] <= 'z' && !isDone; chars[2]++) {
                    for (chars[3] = 'a'; chars[3] <= 'z' && !isDone; chars[3]++) {
                        for (chars[4] = 'a'; chars[4] <= 'z' && !isDone; chars[4]++) {
                            String attempt = new String(chars);
                            byte[] hash = digest.digest(attempt.getBytes());
                            if (Arrays.equals(hash, input)) {
                                match = attempt;
                                isDone = true;
                            }

                        }
                    }
                }
            }
        }

        log.info("Found math for hash '{}' : '{}'. Time spent: '{}' s.", inputStr, match, now.until(now(), MILLIS) / 1000.0);
    }
}