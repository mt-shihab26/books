package com.shihabmahamud.eshoppers.domain;

import java.time.LocalDateTime;

public class Order {
    private Long id;
    private Cart cart;
    private ShippingAddress shippingAddress;
    private LocalDateTime shippingDate;
    private Payment payment;
    private Boolean shipped;
    private User user;

    public Order() {
    }

    public Order(Long id, Cart cart, ShippingAddress shippingAddress,
                 LocalDateTime shippingDate, Payment payment, Boolean shipped, User user) {
        this.id = id;
        this.cart = cart;
        this.shippingAddress = shippingAddress;
        this.shippingDate = shippingDate;
        this.payment = payment;
        this.shipped = shipped;
        this.user = user;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public Cart getCart() {
        return cart;
    }

    public void setCart(Cart cart) {
        this.cart = cart;
    }

    public ShippingAddress getShippingAddress() {
        return shippingAddress;
    }

    public void setShippingAddress(ShippingAddress shippingAddress) {
        this.shippingAddress = shippingAddress;
    }

    public LocalDateTime getShippingDate() {
        return shippingDate;
    }

    public void setShippingDate(LocalDateTime shippingDate) {
        this.shippingDate = shippingDate;
    }

    public Payment getPayment() {
        return payment;
    }

    public void setPayment(Payment payment) {
        this.payment = payment;
    }

    public Boolean getShipped() {
        return shipped;
    }

    public void setShipped(Boolean shipped) {
        this.shipped = shipped;
    }

    public User getUser() {
        return user;
    }

    public void setUser(User user) {
        this.user = user;
    }
}
