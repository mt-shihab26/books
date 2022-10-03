package com.shihabmahamud.eshoppers.service;

import com.shihabmahamud.eshoppers.domain.User;
import com.shihabmahamud.eshoppers.repository.UserRepository;
import com.shihabmahamud.eshoppers.dto.UserDTO;
import org.jetbrains.annotations.NotNull;
import org.jetbrains.annotations.Nullable;

public class UserServiceImpl implements UserService{
    private final UserRepository userRepository;
    public UserServiceImpl(UserRepository userRepository) {
        this.userRepository = userRepository;
    }

    @Override
    public void saveUser(UserDTO userDTO) {
        var encryptedPassword = encryptPassword(userDTO.getPassword());
        var user = new User(
                userDTO.getUsername(),
                userDTO.getEmail(),
                encryptedPassword,
                userDTO.getFirstname(),
                userDTO.getLastname()
        );

        userRepository.save(user);
    }

    @Nullable
    @Override
    public User findUserByUsername(@NotNull String username) {
        return userRepository.findOneByUsername(username);
    }

    private String encryptPassword(String password) {
        return password;
    }
}
