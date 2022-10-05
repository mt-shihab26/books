package com.shihabmahamud.eshoppers.service;

import com.shihabmahamud.eshoppers.domain.Cart;
import com.shihabmahamud.eshoppers.domain.CartItem;
import com.shihabmahamud.eshoppers.domain.Product;
import com.shihabmahamud.eshoppers.domain.User;
import com.shihabmahamud.eshoppers.repository.CartItemRepository;
import com.shihabmahamud.eshoppers.repository.CartRepository;
import com.shihabmahamud.eshoppers.repository.ProductRepository;
import com.shihabmahamud.eshoppers.web.HomeServlet;
import com.shihabmahamud.eshoppers.exceptions.ProductNotFoundException;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.math.BigDecimal;
import java.util.Optional;

public class CartServiceImpl implements CartService {
    private final static Logger LOGGER = LoggerFactory.getLogger(HomeServlet.class);
    private final CartRepository cartRepository;
    private final ProductRepository productRepository;
    private final CartItemRepository cartItemRepository;

    public CartServiceImpl(CartRepository cartRepository, ProductRepository productRepository,
                           CartItemRepository cartItemRepository) {
        this.cartRepository = cartRepository;
        this.productRepository = productRepository;
        this.cartItemRepository = cartItemRepository;
    }

    @Override
    public Cart getCartByUser(User currentUser) {
        var cart = cartRepository.findByUser(currentUser);
        if (cart == null) {
            cart = createNewCart(currentUser);
        }
        return cart;
    }

    @Override
    public void addProductToCart(String productId, Cart cart) throws ProductNotFoundException {
        if (productId == null || productId.length() == 0) {
            throw new IllegalArgumentException("Product id cannot be null");
        }
        Long id = parseProductId(productId);

        Product product = productRepository.findById(id);
        if (product == null) {
            throw new ProductNotFoundException("Product not found by id: " + id);
        }

        addProductToCart(product, cart);

        Integer totalTotalItem = getTotalItem(cart);
        BigDecimal totalPrice = calculateTotalPrice(cart);

        cart.setTotalItem(totalTotalItem);
        cart.setTotalPrice(totalPrice);

        cartRepository.update(cart);
    }

    private void addProductToCart(Product product, Cart cart) {
        var cartItemOptional = findSimilarProductInCart(cart, product);
        var cartItem = cartItemOptional
                .map(this::increaseQuantityByOne)
                .orElseGet(() -> createNewShoppingCartItem(product));

        cart.getCartItems().add(cartItem);
    }

    private CartItem createNewShoppingCartItem(Product product) {
        var cartItem = new CartItem();
        cartItem.setProduct(product);
        cartItem.setQuantity(1);
        cartItem.setPrice(product.getPrice());
        return cartItemRepository.save(cartItem);
    }

    private CartItem increaseQuantityByOne(CartItem cartItem) {
        cartItem.setQuantity(cartItem.getQuantity() + 1);
        BigDecimal totalPrice = cartItem
                .getProduct()
                .getPrice()
                .multiply(BigDecimal.valueOf(cartItem.getQuantity()));
        cartItem.setPrice(totalPrice);
        return cartItemRepository.update(cartItem);
    }

    private Optional<CartItem> findSimilarProductInCart(Cart cart, Product product) {
        return cart
                .getCartItems()
                .stream()
                .filter(cartItem -> cartItem.getProduct().equals(product))
                .findFirst();
    }

    private Integer getTotalItem(Cart cart) {
        return cart.getCartItems()
                .stream()
                .map(CartItem::getQuantity)
                .reduce(0, Integer::sum);
    }

    private BigDecimal calculateTotalPrice(Cart cart) {
        return cart
                .getCartItems()
                .stream()
                .map(CartItem::getPrice)
                .reduce(BigDecimal.ZERO, BigDecimal::add);
    }

    private Long parseProductId(String productId) {
        try {
            return Long.parseLong(productId);
        } catch (NumberFormatException e) {
            throw new IllegalArgumentException("Product id must be a number", e);
        }
    }

    private Cart createNewCart(User currentUser) {
        var cart = new Cart();
        cart.setUser(currentUser);
        return cartRepository.save(cart);
    }
}
