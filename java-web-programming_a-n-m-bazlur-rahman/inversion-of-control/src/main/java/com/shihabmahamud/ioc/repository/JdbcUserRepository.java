package com.shihabmahamud.ioc.repository;

import com.shihabmahamud.ioc.domain.User;

public class JdbcUserRepository implements UserRepository {
    @Override
    public User save(User user) {
        // store user in database
        return user;
    }
}
