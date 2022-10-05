package com.shihabmahamud.eshoppers.repository;

import com.shihabmahamud.eshoppers.domain.ShippingAddress;

public interface ShippingAddressRepository {
    ShippingAddress save(ShippingAddress shippingAddress);
}
