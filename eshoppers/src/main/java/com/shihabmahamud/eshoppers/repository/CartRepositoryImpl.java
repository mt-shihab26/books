package com.shihabmahamud.eshoppers.repository;

import com.shihabmahamud.eshoppers.domain.Cart;
import com.shihabmahamud.eshoppers.domain.Order;
import com.shihabmahamud.eshoppers.domain.User;

import java.util.Arrays;
import java.util.LinkedHashSet;
import java.util.Map;
import java.util.Set;
import java.util.concurrent.ConcurrentHashMap;

public class CartRepositoryImpl implements CartRepository{
    private static final Map<User, Set<Cart>> CARTS = new ConcurrentHashMap<>();
    private static final OrderRepository orderRepository = new OrderRepositoryImpl();

    @Override
    public Cart findByUser(User currentUser) {
        Set<Cart> carts = CARTS.get(currentUser);
        if (carts == null || carts.isEmpty()) return null;

        var cart = (Cart) carts.toArray()[carts.size() - 1];

        var orders = orderRepository.findOrderByUser(currentUser);
        if (orders == null) return cart;

        for (Order order : orders) {
            if (order.getCart().equals(cart)) {
                return null;
            }
        }
        return cart;
    }

    @Override
    public Cart save(Cart cart) {
        CARTS.computeIfPresent(cart.getUser(), (user, carts) -> {
            carts.add(cart);
            return carts;
        });
        CARTS.computeIfAbsent(cart.getUser(), user -> {
            var carts = new LinkedHashSet<Cart>();
            carts.add(cart);
            return carts;
        });
        return cart;
    }


    @Override
    public Cart update(Cart cart) {
        CARTS.computeIfPresent(cart.getUser(), (user, carts) -> {
            Cart[] objects = carts.toArray(Cart[]::new);
            objects[objects.length-1] = cart;
            return new LinkedHashSet<>(Arrays.asList(objects));
        });
        return cart;
    }
}