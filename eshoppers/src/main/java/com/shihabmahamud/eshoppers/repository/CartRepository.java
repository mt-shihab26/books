package com.shihabmahamud.eshoppers.repository;

import com.shihabmahamud.eshoppers.domain.Cart;
import com.shihabmahamud.eshoppers.domain.User;

import java.util.Optional;

public interface CartRepository {
    Optional<Cart> findByUser(User currentUser);
    Optional<Cart> findOne(long cartId);
    Cart save(Cart cart);
    Cart update(Cart cart);
}
