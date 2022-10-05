package com.shihabmahamud.eshoppers.repository;

import com.shihabmahamud.eshoppers.domain.Order;

public interface OrderRepository {
    Order save(Order order);
}
