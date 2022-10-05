package com.shihabmahamud.eshoppers.service;

import com.shihabmahamud.eshoppers.domain.Cart;
import com.shihabmahamud.eshoppers.domain.User;
import com.shihabmahamud.eshoppers.exceptions.ProductNotFoundException;

public interface CartService {
    Cart getCartByUser(User currentUser);

    void addProductToCart(String productId, Cart cart) throws ProductNotFoundException;
}
