package com.shihabmahamud.cdi.repository;

import com.shihabmahamud.cdi.domain.User;

import javax.enterprise.inject.Default;

@Default
public class JdbcUserRepository implements UserRepository {
    @Override
    public User save(User user) {
        // store user in database
        System.out.println("Inside JdbcUserRepository::save()");
        return user;
    }
}
