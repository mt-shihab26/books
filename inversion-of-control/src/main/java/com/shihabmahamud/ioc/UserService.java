package com.shihabmahamud.ioc;

public class UserService {
    private final JdbcUserRepository userRepository = new JdbcUserRepository();
    private final MD5PasswordEncryption encryption = new MD5PasswordEncryption();

    public User saveUser(User user) {
        user.setPassword(encryption.encrypt(user.getPassword()));
        return userRepository.save(user);
    }
}
