package com.shihabmahamud.cdi;

import javax.inject.Inject;

public class UserService {

    @Inject
    @Remote
    private UserRepository userRepository;

    @Inject
    @Sha256
    private PasswordEncryption encryption;

    public void saveUser(User user) {
        user.setPassword(encryption.encrypt(user.getPassword()));

        userRepository.save(user);
    }
}