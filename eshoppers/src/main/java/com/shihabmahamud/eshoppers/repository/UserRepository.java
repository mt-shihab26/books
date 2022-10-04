package com.shihabmahamud.eshoppers.repository;

import com.shihabmahamud.eshoppers.domain.User;

import java.util.Optional;

public interface UserRepository {
    void save(User user);

    Optional<User> findOneByUsername(String username);
}
