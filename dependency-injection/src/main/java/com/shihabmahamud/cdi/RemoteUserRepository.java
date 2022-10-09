package com.shihabmahamud.cdi.repository;

import com.shihabmahamud.cdi.annotations.Remote;
import com.shihabmahamud.cdi.domain.User;

@Remote
public class RemoteUserRepository implements UserRepository{
    @Override
    public User save(User user) {
        // send user in other server
        System.out.println("Inside RemoteUserRepository::save()");
        return user;
    }
}
