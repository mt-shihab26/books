package com.shihabmahamud.cdi.service;

import com.shihabmahamud.cdi.annotations.Sha256;
import com.shihabmahamud.cdi.domain.User;
import com.shihabmahamud.cdi.repository.UserRepository;
import com.shihabmahamud.cdi.util.PasswordEncryption;

import javax.enterprise.inject.Default;
import javax.inject.Inject;

public class UserService {
    // now this UserService class is CDI Bean
    @Inject
    @Default
    private UserRepository userRepository;

    @Inject
    @Sha256
    private PasswordEncryption passwordEncryption;


    public void saveUser(User user) {
        System.out.println("Inside UserService::saveUser()");

        user.setPassword(passwordEncryption.encrypt(user.getPassword()));
        userRepository.save(user);
    }
}
