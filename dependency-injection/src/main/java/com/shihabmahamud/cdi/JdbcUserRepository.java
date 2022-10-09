package com.shihabmahamud.cdi;

import javax.enterprise.inject.Default;

@Default
public class JdbcUserRepository implements UserRepository {

    @Override
    public User save(User user) {
        //store in db
        System.out.println("Inside JdbcUserRepository::save()");
        return user;
    }
}
