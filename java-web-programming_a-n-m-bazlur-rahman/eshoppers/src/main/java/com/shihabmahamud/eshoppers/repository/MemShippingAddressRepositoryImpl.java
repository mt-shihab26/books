package com.shihabmahamud.eshoppers.repository;

import com.shihabmahamud.eshoppers.domain.ShippingAddress;

import java.util.Set;
import java.util.concurrent.CopyOnWriteArraySet;

public class MemShippingAddressRepositoryImpl implements ShippingAddressRepository {
    private static final Set<ShippingAddress> SHIPPING_ADDRESSES = new CopyOnWriteArraySet<>();
    @Override
    public ShippingAddress save(ShippingAddress shippingAddress) {
        SHIPPING_ADDRESSES.add(shippingAddress);
        return shippingAddress;
    }

    @Override
    public ShippingAddress findOne(Long shippingAddressId) {
        var sap = SHIPPING_ADDRESSES
                .stream()
                .filter(shippingAddress -> shippingAddress.getId().equals(shippingAddressId))
                .findFirst();
        if (sap.isEmpty()) return null;
        return sap.get();
    }
}
