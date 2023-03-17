package com.shihabmahamud.cdi;

@Remote
public class RemoteUserRepository implements UserRepository{
    @Override
    public User save(User user) {
        // send user in other server
        System.out.println("Inside RemoteUserRepository::save()");
        return user;
    }
}
