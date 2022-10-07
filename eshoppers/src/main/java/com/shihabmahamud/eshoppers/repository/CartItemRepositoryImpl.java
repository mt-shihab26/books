package com.shihabmahamud.eshoppers.repository;

import com.shihabmahamud.eshoppers.domain.Cart;
import com.shihabmahamud.eshoppers.domain.CartItem;

import java.util.Objects;
import java.util.Set;
import java.util.concurrent.CopyOnWriteArraySet;

public class CartItemRepositoryImpl implements CartItemRepository {
    private static final Set<CartItem> CARTS = new CopyOnWriteArraySet<>();

    @Override
    public CartItem save(CartItem cartItem, Cart cart) {
        CARTS.add(cartItem);
        return cartItem;
    }

    @Override
    public CartItem update(CartItem cartItem) {
        CARTS.add(cartItem);
        return cartItem;
    }

    @Override
    public void remove(CartItem cartItem) {
        CARTS.remove(cartItem);
    }

    @Override
    public CartItem findOne(Long id) {
        var cartItem0 = CARTS.stream()
                .filter(cartItem -> Objects.equals(cartItem.getId(), id))
                .findFirst();
        if (cartItem0.isEmpty()) return null;
        return cartItem0.get();
    }
}
