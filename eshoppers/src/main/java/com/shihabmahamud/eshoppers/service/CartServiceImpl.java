package com.shihabmahamud.eshoppers.service;

import com.shihabmahamud.eshoppers.domain.Cart;
import com.shihabmahamud.eshoppers.domain.CartItem;
import com.shihabmahamud.eshoppers.domain.Product;
import com.shihabmahamud.eshoppers.domain.User;
import com.shihabmahamud.eshoppers.exceptions.CartItemNotFoundException;
import com.shihabmahamud.eshoppers.repository.*;
import com.shihabmahamud.eshoppers.repository.CartItemRepository;
import com.shihabmahamud.eshoppers.repository.CartRepository;
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
    private final UserRepository userRepository;

    public CartServiceImpl(CartRepository cartRepository,
                           ProductRepository productRepository,
                           CartItemRepository cartItemRepository,
                           UserRepository userRepository)
    {
        this.cartRepository = cartRepository;
        this.productRepository = productRepository;
        this.cartItemRepository = cartItemRepository;
        this.userRepository = userRepository;
    }

    @Override
    public Cart getCartByUser(User currentUser) {
        if (currentUser.getId() == null)
            currentUser = userRepository.findOneByUsername(currentUser.getUsername());

        var cart = cartRepository.findByUser(currentUser);
        if (cart == null) {
            cart = new Cart();
            cart.setUser(currentUser);
            cart = cartRepository.save(cart);
        }
        return cart;
    }

    @Override
    public void addProductToCart(String productId, Cart cart)
            throws ProductNotFoundException
    {
        Product product =  findProduct(productId);

        var cartItemOptional = findSimilarProductInCart(cart, product);
        var cartItem = cartItemOptional
                .map(this::increaseQuantityByOne)
                .orElseGet(() -> createNewShoppingCartItem(product, cart));

        cart.getCartItems().add(cartItem);

        updateCart(cart);
    }

    @Override
    public void removeProductToCart(String productId, Cart cart)
            throws ProductNotFoundException, CartItemNotFoundException
    {
        Product product = findProduct(productId);

        var itemOptional = cart.getCartItems()
                .stream()
                .filter(cartItem -> cartItem.getProduct().equals(product))
                .findAny();

        var cartItem = itemOptional
                .orElseThrow(() -> new CartItemNotFoundException("Cart not found by product: " + product));

        if (cartItem.getQuantity() > 1) {
            cartItem.setQuantity(cartItem.getQuantity()-1);
            cartItem.setPrice(cartItem.getPrice().subtract(product.getPrice()));
            cartItemRepository.update(cartItem);
        } else {
            cart.getCartItems().remove(cartItem);
            cartItemRepository.remove(cartItem);
        }

        updateCart(cart);
    }

    @Override
    public void removeProductTotallyToCart(String productId, Cart cart)
            throws ProductNotFoundException, CartItemNotFoundException
    {
        Product product = findProduct(productId);

        var itemOptional = cart.getCartItems()
                .stream()
                .filter(cartItem -> cartItem.getProduct().equals(product))
                .findAny();

        var cartItem = itemOptional
                .orElseThrow(() -> new CartItemNotFoundException("Cart not found by product: " + product));

        cart.getCartItems().remove(cartItem);
        cartItemRepository.remove(cartItem);

        updateCart(cart);
    }

    private Product findProduct(String productId)
            throws ProductNotFoundException
    {
        if (productId == null || productId.length() == 0)
            throw new IllegalArgumentException("Product id cannot be null");
        long id;
        try {
            id = Long.parseLong(productId);
        } catch (NumberFormatException e) {
            throw new IllegalArgumentException("Product id must be a number", e);
        }

        Product product = productRepository.findById(id);
        if (product == null)
            throw new ProductNotFoundException("Product not found by id: " + id);
        return product;
    }

    private void updateCart(Cart cart) {
        Integer totalTotalItem = getTotalItem(cart);
        BigDecimal totalPrice = calculateTotalPrice(cart);

        cart.setTotalItem(totalTotalItem);
        cart.setTotalPrice(totalPrice);

        cartRepository.update(cart);
    }

    private CartItem createNewShoppingCartItem(Product product, Cart cart) {
        var cartItem = new CartItem();
        cartItem.setProduct(product);
        cartItem.setQuantity(1);
        cartItem.setPrice(product.getPrice());
        return cartItemRepository.save(cartItem, cart);
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
        LOGGER.info("Here cart");
        LOGGER.info(cart.toString());

        var sum = 0;
        for (CartItem cartItem : cart.getCartItems()) {
            System.out.println(sum);
            sum += cartItem.getQuantity();
        }
        return sum;
    }

    private BigDecimal calculateTotalPrice(Cart cart) {
        return cart
                .getCartItems()
                .stream()
                .map(CartItem::getPrice)
                .reduce(BigDecimal.ZERO, BigDecimal::add);
    }
}
