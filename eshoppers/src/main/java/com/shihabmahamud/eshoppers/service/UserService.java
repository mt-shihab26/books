package com.shihabmahamud.eshoppers.service;

import com.shihabmahamud.eshoppers.dto.UserDTO;

public interface UserService {
    void saveUser(UserDTO userDTO);
    Boolean isNotUniqueUsername(UserDTO userDTO);
}
