package com.shihabmahamud.eshoppers.repository;

import com.shihabmahamud.eshoppers.domain.User;

public interface UserRepository {
    User save(User user);
    User update(User user);
    void remove(User user);

    User findOneByUsername(String username);
    User findOneById(Long id);
}
