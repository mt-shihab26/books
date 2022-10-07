package com.shihabmahamud.eshoppers.repository;

import com.shihabmahamud.eshoppers.domain.CartItem;
import com.shihabmahamud.eshoppers.exceptions.CartItemNotFoundException;
import com.shihabmahamud.eshoppers.exceptions.OptimisticLockingFailureException;

public interface CartItemRepository {
    CartItem save(CartItem cartItem);
    CartItem update(CartItem cartItem) throws CartItemNotFoundException, OptimisticLockingFailureException;
    void remove(CartItem cartItem);
    public CartItem findOne(Long id);

}
