package com.shihabmahamud.eshoppers.service;

import com.shihabmahamud.eshoppers.domain.Order;
import com.shihabmahamud.eshoppers.domain.ShippingAddress;
import com.shihabmahamud.eshoppers.domain.User;
import com.shihabmahamud.eshoppers.dto.ShippingAddressDTO;
import com.shihabmahamud.eshoppers.exceptions.CartItemNotFoundException;
import com.shihabmahamud.eshoppers.repository.*;

public class OrderServiceImpl implements OrderService {
    private final OrderRepository orderRepository;
    private final ShippingAddressRepository shippingAddressRepository;
    private final CartRepository cartRepository;

    public OrderServiceImpl(OrderRepository orderRepository,
                            ShippingAddressRepository shippingAddressRepository,
                            CartRepository cartRepository) {
        this.orderRepository = orderRepository;
        this.shippingAddressRepository = shippingAddressRepository;
        this.cartRepository = cartRepository;
    }

    @Override
    public void processOrder(ShippingAddressDTO shippingAddressDTO, User currentUser)
            throws CartItemNotFoundException {
        var shippingAddress = convertTo(shippingAddressDTO);
        var savedShippingAddress = shippingAddressRepository.save(shippingAddress);

        var cart = cartRepository.findByUser(currentUser);
        if (cart == null) {
            throw new CartItemNotFoundException("Cart Not found by current users");
        }

        Order order = new Order();
        order.setCart(cart);
        order.setShippingAddress(savedShippingAddress);
        order.setShipped(false);
        order.setUser(currentUser);

        orderRepository.save(order);
    }

    private ShippingAddress convertTo(ShippingAddressDTO shippingAddressDTO) {
        return new ShippingAddress(
                shippingAddressDTO.getAddress(),
                shippingAddressDTO.getAddress2(),
                shippingAddressDTO.getCountry(),
                shippingAddressDTO.getState(),
                shippingAddressDTO.getState(),
                shippingAddressDTO.getMobileNumber()
        );
    }
}
