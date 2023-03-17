package com.shihabmahamud.eshoppers.service;

import com.shihabmahamud.eshoppers.domain.User;
import com.shihabmahamud.eshoppers.dto.LoginDTO;
import com.shihabmahamud.eshoppers.dto.UserDTO;

public interface UserService {
    void saveUser(UserDTO userDTO);
    Boolean isNotUniqueUsername(UserDTO userDTO);
    User verifyUser(LoginDTO loginDTO);
}