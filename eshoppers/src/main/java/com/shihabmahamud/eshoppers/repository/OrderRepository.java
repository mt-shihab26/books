package com.shihabmahamud.eshoppers.repository;

import com.shihabmahamud.eshoppers.domain.Order;
import com.shihabmahamud.eshoppers.domain.User;

import java.util.Set;

public interface OrderRepository {
    Order save(Order order);
    Set<Order> findOrderByUser(User currentUser);
}
