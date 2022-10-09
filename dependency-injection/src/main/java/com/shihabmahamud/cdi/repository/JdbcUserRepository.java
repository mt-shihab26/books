package com.shihabmahamud.cdi.repository;

import com.shihabmahamud.cdi.domain.User;

public class JdbcUserRepository implements UserRepository {
    @Override
    public User save(User user) {
        // store user in database
        return user;
    }
}
