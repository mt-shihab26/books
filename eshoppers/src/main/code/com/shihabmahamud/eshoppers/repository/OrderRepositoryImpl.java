package com.shihabmahamud.eshoppers.repository;

import com.shihabmahamud.eshoppers.domain.Order;
import com.shihabmahamud.eshoppers.domain.User;

import java.util.Objects;
import java.util.Set;
import java.util.concurrent.CopyOnWriteArraySet;

public class OrderRepositoryImpl implements OrderRepository {
    private static final Set<Order> ORDERS = new CopyOnWriteArraySet<>();

    @Override
    public Order save(Order order) {
        ORDERS.add(order);
        return order;
    }

    @Override
    public Set<Order> findOrderByUser(User currentUser) {
        Set<Order> orderOfUser = new CopyOnWriteArraySet<>();
        for (Order order : ORDERS) {
            if (Objects.equals(order.getUser(), currentUser)) {
                orderOfUser.add(order);
            }
        }
        if (orderOfUser.size() == 0) {
            return null;
        }
        return orderOfUser;
    }
}
