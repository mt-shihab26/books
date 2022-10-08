package com.shihabmahamud.eshoppers.domain;

import java.math.BigDecimal;
import java.util.HashSet;
import java.util.Objects;
import java.util.Set;

public class Cart extends Domain {
    private Set<CartItem> cartItems = new HashSet<>();
    private BigDecimal totalPrice = BigDecimal.ZERO;
    private Integer totalItem = 0;
    private User user;

    public Cart() {

    }
    public Cart(User user) {
        this.user = user;
    }

    public Cart(Long id, BigDecimal totalPrice, Integer totalItem, User user) {
        setId(id);
        this.totalPrice = totalPrice;
        this.totalItem = totalItem;
        this.user = user;
    }

    public Set<CartItem> getCartItems() {
        return cartItems;
    }

    public void setCartItems(Set<CartItem> cartItems) {
        this.cartItems = cartItems;
    }

    public BigDecimal getTotalPrice() {
        return totalPrice;
    }

    public void setTotalPrice(BigDecimal totalPrice) {
        this.totalPrice = totalPrice;
    }

    public Integer getTotalItem() {
        return totalItem;
    }

    public void setTotalItem(Integer totalItem) {
        this.totalItem = totalItem;
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
        if (!(o instanceof Cart cart)) return false;
        return Objects.equals(getId(), cart.getId());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getId());
    }

    @Override
    public String toString() {
        return "Cart{" +
                "cartItems=" + cartItems +
                ", totalPrice=" + totalPrice +
                ", totalItem=" + totalItem +
                ", user=" + user +
                '}';
    }
}
