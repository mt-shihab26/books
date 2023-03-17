package com.shihabmahamud.eshoppers.repository;

import com.shihabmahamud.eshoppers.domain.User;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.util.Objects;
import java.util.Set;
import java.util.concurrent.CopyOnWriteArraySet;

public class MemUserRepositoryImpl implements UserRepository {
    private final Set<User> USERS = new CopyOnWriteArraySet<>();
    private final Logger LOGGER = LoggerFactory.getLogger(MemUserRepositoryImpl.class);

    @Override
    public User save(User user) {
        USERS.add(user);
        LOGGER.debug(USERS.toString());
        return user;
    }

    @Override
    public User findOneByUsername(String username) {
        var userOp = USERS
                .stream()
                .filter(user -> Objects.equals(user.getUsername(), username))
                .findFirst();

        if (userOp.isEmpty())
            return null;

        return userOp.get();
    }
}
