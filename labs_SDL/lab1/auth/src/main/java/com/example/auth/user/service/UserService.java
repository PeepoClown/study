package com.example.auth.user.service;

import com.example.auth.user.dao.UserDao;
import com.example.auth.user.model.User;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.apache.commons.lang3.tuple.ImmutablePair;
import org.mindrot.jbcrypt.BCrypt;
import org.springframework.lang.NonNull;
import org.springframework.stereotype.Service;

import java.time.LocalDateTime;
import java.time.temporal.ChronoUnit;
import java.util.Optional;

import static java.time.LocalDateTime.MIN;
import static java.time.LocalDateTime.now;
import static java.util.Optional.empty;
import static java.util.Optional.of;

@Slf4j
@Service
@RequiredArgsConstructor
public class UserService {

    private static final int MAX_FAILED_ATTEMPTS = 5;
    private static int currFailedAttempts = 0;
    private static LocalDateTime lastBlock = MIN;
    private static LocalDateTime lastUnblock = MIN;

    private final UserDao userDao;

    public Optional<User> create(@NonNull String username, @NonNull String password) {
        try {
            var user = new User()
                    .setUsername(username)
                    .setPassword(BCrypt.hashpw(password, BCrypt.gensalt()));

            return of(userDao.save(user));
        } catch (Exception e) {
            log.info("Failed to create user. {}", e.getMessage(), e);
            return empty();
        }
    }

    public ImmutablePair<Optional<User>, Long> authenticate(@NonNull String username, @NonNull String password) {
        if (currFailedAttempts == MAX_FAILED_ATTEMPTS) {
            if (lastBlock.equals(MIN)) {
                lastBlock = now();
                lastUnblock = lastBlock.plusMinutes(1);
            }
            var timeDiff = ChronoUnit.SECONDS.between(now(), lastUnblock);
            if (timeDiff < 60L && timeDiff >= 0L) {
                log.info("Timeout. Until {} s.", timeDiff);
                return ImmutablePair.of(empty(), timeDiff);
            } else {
                currFailedAttempts = 0;
                lastBlock = MIN;
            }
        }

        var user = userDao.findByUsername(username);
        if (user.isEmpty()) {
            currFailedAttempts++;
            log.info("User not found {}. Attempts {}", username, currFailedAttempts);
            return ImmutablePair.of(user, -1L);
        }

        if (BCrypt.checkpw(password, user.get().getPassword())) {
            log.info("Auth  success");
            return ImmutablePair.of(user, -1L);
        } else {
            currFailedAttempts++;
            log.info("Invalid password for user {}. Attempts {}", username, currFailedAttempts);
            return ImmutablePair.of(empty(), -1L);
        }
    }

}
