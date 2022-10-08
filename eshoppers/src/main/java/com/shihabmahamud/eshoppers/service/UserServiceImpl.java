package com.shihabmahamud.eshoppers.service;

import com.shihabmahamud.eshoppers.domain.User;
import com.shihabmahamud.eshoppers.dto.LoginDTO;
import com.shihabmahamud.eshoppers.dto.UserDTO;
import com.shihabmahamud.eshoppers.exceptions.UserNotFoundException;
import com.shihabmahamud.eshoppers.repository.JdbcUserRepositoryImpl;
import com.shihabmahamud.eshoppers.repository.UserRepository;

import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Objects;

public class UserServiceImpl implements  UserService {
    private final UserRepository userRepository;

    public UserServiceImpl(UserRepository userRepository) {
        this.userRepository = userRepository;
    }

    @Override
    public void saveUser(UserDTO userDTO) {
        var user = new User();

        user.setUsername(userDTO.getUsername());
        user.setEmail(userDTO.getEmail());
        user.setPassword(userDTO.getPassword());
        user.setFirstname(userDTO.getFirstname());
        user.setLastname(userDTO.getLastname());

        userRepository.save(user);
    }

    @Override

    public Boolean isNotUniqueUsername(UserDTO userDTO) {
        var user = userRepository.findOneByUsername(userDTO.getUsername());
        return user != null;
    }

    @Override
    public User verifyUser(LoginDTO loginDTO) {
        var user = userRepository.findOneByUsername(loginDTO.getUsername());

        if (user == null)
            throw new UserNotFoundException("User not found by " + loginDTO.getUsername());

        var encrypted = encryptPassword(loginDTO.getPassword());
        if (user.getPassword().equals(encrypted)) {

            return user;
        } else {
            throw new UserNotFoundException("Incorrect username password");
        }
    }

    private String encryptPassword(String password) {
        try {
            var digest = MessageDigest.getInstance("SHA-256");
            var bytes = digest.digest(
                    password.getBytes(StandardCharsets.UTF_8)
            );

            return bytesToHex(bytes);
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException("Unable to encrypt password", e);
        }
    }

    private static String bytesToHex(byte[] hash) {
        StringBuilder hexString = new StringBuilder();
        for (byte b : hash) {
            String hex = Integer.toHexString(0xff & b);
            if (hex.length() == 1) {
                hexString.append('0');
            }
            hexString.append(hex);
        }
        return hexString.toString();
    }
}
