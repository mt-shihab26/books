package com.shihabmahamud.ioc;

import com.shihabmahamud.ioc.repository.JdbcUserRepository;
import com.shihabmahamud.ioc.service.UserService;
import com.shihabmahamud.ioc.util.MD5PasswordEncryption;

public class Main {
    private final UserService userService = new UserService(
            new JdbcUserRepository(),
            new MD5PasswordEncryption()
    );

    public static void main(String[] args) {
        System.out.println("Hello world!");
    }
}