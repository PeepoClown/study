package com.example.auth;

import com.example.auth.user.service.UserService;
import lombok.RequiredArgsConstructor;
import lombok.extern.slf4j.Slf4j;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import static java.lang.String.format;
import static org.hibernate.internal.util.StringHelper.isBlank;
import static org.springframework.http.HttpStatus.BAD_REQUEST;
import static org.springframework.http.HttpStatus.INTERNAL_SERVER_ERROR;
import static org.springframework.http.HttpStatus.UNAUTHORIZED;
import static org.springframework.http.ResponseEntity.ok;
import static org.springframework.http.ResponseEntity.status;

@Slf4j
@RestController
@RequiredArgsConstructor
@RequestMapping(path = "api/public/v1/users")
public class AuthController {

    private final UserService userService;

    @PostMapping
    public ResponseEntity<?> create(@RequestParam("username") String username,
                                    @RequestParam("password") String password) {
        log.info("Received new create user request. {}, {}", username, password);
        if (isBlank(username) || isBlank(password)) {
            return status(BAD_REQUEST).body("Required params are not set");
        }

        var response = userService.create(username, password);
        if (response.isEmpty()) {
            return status(INTERNAL_SERVER_ERROR).body("Failed to create user");
        }
        return ok().body(response.get());
    }

    @PostMapping
    public ResponseEntity<?> auth(@RequestParam("username") String username,
                                  @RequestParam("password") String password) {
        log.info("Received new auth request. {}, {}", username, password);
        if (isBlank(username) || isBlank(password)) {
            return status(BAD_REQUEST).body("Required params are not set");
        }

        var response = userService.authenticate(username, password);
        if (response.right > 0) {
            return status(BAD_REQUEST).body(format("You temporally locked to this endpoint by %d seconds", response.right));
        }
        if (response.left.isEmpty()) {
            return status(UNAUTHORIZED).body(format("Username/password [%s/%s] is incorrect", username, password));
        }
        return ok().body(response.left.get());
    }

}
