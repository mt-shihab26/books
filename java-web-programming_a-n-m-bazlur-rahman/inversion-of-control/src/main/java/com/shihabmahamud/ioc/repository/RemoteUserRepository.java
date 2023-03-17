package com.shihabmahamud.ioc.repository;

import com.shihabmahamud.ioc.domain.User;

public class RemoteUserRepository implements UserRepository{
    @Override
    public User save(User user) {
        // send user in other server
        return user;
    }
}
