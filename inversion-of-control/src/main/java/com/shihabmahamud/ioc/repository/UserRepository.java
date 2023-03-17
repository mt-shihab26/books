package com.shihabmahamud.ioc.repository;

import com.shihabmahamud.ioc.domain.User;

public interface UserRepository {
    User save(User user);
}
