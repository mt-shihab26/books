package com.shihabmahamud.eshoppers.service;

import com.shihabmahamud.eshoppers.domain.User;
import com.shihabmahamud.eshoppers.dto.ShippingAddressDTO;
import com.shihabmahamud.eshoppers.exceptions.CartItemNotFoundException;

public interface OrderService {
    void processOrder(ShippingAddressDTO shippingAddressDTO, User currentUser) throws CartItemNotFoundException;
}
