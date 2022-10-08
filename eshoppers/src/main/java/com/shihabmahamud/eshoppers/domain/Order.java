package com.shihabmahamud.eshoppers.domain;

import java.time.LocalDateTime;
import java.util.Objects;

public class Order extends Domain{
    private Cart cart;
    private ShippingAddress shippingAddress;
    private LocalDateTime shippingDate;
    private Payment payment;
    private Boolean shipped;
    private User user;

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

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Order order)) return false;
        return Objects.equals(getId(), order.getId());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getId());
    }

    @Override
    public String toString() {
        return "Order{" +
                "cart=" + cart +
                ", shippingAddress=" + shippingAddress +
                ", shippingDate=" + shippingDate +
                ", payment=" + payment +
                ", shipped=" + shipped +
                ", user=" + user +
                '}';
    }
}
