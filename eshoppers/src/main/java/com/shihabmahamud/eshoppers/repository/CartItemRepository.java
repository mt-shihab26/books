package com.shihabmahamud.eshoppers.repository;

import com.shihabmahamud.eshoppers.domain.CartItem;

public interface CartItemRepository {
    CartItem save(CartItem cartItem);
    CartItem update(CartItem cartItem);
}
