package com.shihabmahamud.eshoppers.service;

import com.shihabmahamud.eshoppers.domain.User;
import com.shihabmahamud.eshoppers.dto.UserDTO;
import org.jetbrains.annotations.NotNull;
import org.jetbrains.annotations.Nullable;

public interface UserService {
    void saveUser(UserDTO userDTO);

    @Nullable
    User findUserByUsername(@NotNull String username);
}
