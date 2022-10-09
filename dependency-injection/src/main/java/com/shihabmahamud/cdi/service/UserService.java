package com.shihabmahamud.cdi.service;

import com.shihabmahamud.cdi.domain.User;
import com.shihabmahamud.cdi.repository.UserRepository;
import com.shihabmahamud.cdi.util.PasswordEncryption;

import javax.inject.Inject;

public class UserService {
    // now this UserService class is CDI Bean
    @Inject
    private UserRepository userRepository;

    @Inject
    private PasswordEncryption passwordEncryption;


    public void saveUser(User user) {
        user.setPassword(passwordEncryption.encrypt(user.getPassword()));
        userRepository.save(user);
    }
}
