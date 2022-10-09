package com.shihabmahamud.eshoppers.exceptions;

public class CartItemNotFoundException extends RuntimeException {
    public CartItemNotFoundException(String s) {
        super(s);
    }
}
