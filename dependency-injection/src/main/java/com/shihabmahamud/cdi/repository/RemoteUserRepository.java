package com.shihabmahamud.cdi.repository;

import com.shihabmahamud.cdi.domain.User;

public class RemoteUserRepository implements UserRepository{
    @Override
    public User save(User user) {
        // send user in other server
        return user;
    }
}
