package com.shihabmahamud.ioc.service;

import com.shihabmahamud.ioc.domain.User;
import com.shihabmahamud.ioc.repository.UserRepository;
import com.shihabmahamud.ioc.util.PasswordEncryption;

public class UserService {
    private final UserRepository userRepository;
    private final PasswordEncryption passwordEncryption;

    public UserService(UserRepository userRepository,
                       PasswordEncryption passwordEncryption)
    {
        this.userRepository = userRepository;
        this.passwordEncryption = passwordEncryption;
    }

    public User saveUser(User user) {
        user.setPassword(passwordEncryption.encrypt(user.getPassword()));
        return userRepository.save(user);
    }
}
