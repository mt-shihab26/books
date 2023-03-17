package com.shihabmahamud.eshoppers.web;

import com.shihabmahamud.eshoppers.domain.Cart;
import com.shihabmahamud.eshoppers.exceptions.CartItemNotFoundException;
import com.shihabmahamud.eshoppers.exceptions.CartNotFoundException;
import com.shihabmahamud.eshoppers.exceptions.ProductNotFoundException;
import com.shihabmahamud.eshoppers.repository.JdbcCartItemRepositoryImpl;
import com.shihabmahamud.eshoppers.repository.JdbcCartRepositoryImpl;
import com.shihabmahamud.eshoppers.repository.JdbcProductRepositoryImpl;
import com.shihabmahamud.eshoppers.repository.JdbcUserRepositoryImpl;
import com.shihabmahamud.eshoppers.service.Action;
import com.shihabmahamud.eshoppers.service.CartService;
import com.shihabmahamud.eshoppers.service.CartServiceImpl;
import com.shihabmahamud.eshoppers.util.SecurityContext;
import com.shihabmahamud.eshoppers.util.StringUtil;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import javax.inject.Inject;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.Optional;

@WebServlet("/add-to-cart")
public class CartServlet extends HttpServlet {

    @Inject
    private CartService cartService;
    private final static Logger LOGGER = LoggerFactory.getLogger(HomeServlet.class);
    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp)
            throws IOException
    {
        var productId = req.getParameter("productId");
        var action = req.getParameter("action");
        var cart = getCart(req);

        if (cart.isEmpty()){
            throw new CartNotFoundException("Cart not found");
        }

        if (StringUtil.isNotEmpty(action)) {
            try {
                processCart(productId, action, cart.get());
            } catch (ProductNotFoundException | CartItemNotFoundException e) {
                LOGGER.error(String.valueOf(e));
            }

            resp.sendRedirect("/checkout");
            return;
        }

        LOGGER.info("Received request to add product with id: {} to cart", productId);
        try {
            cartService.addProductToCart(productId, cart.get());
        } catch (ProductNotFoundException e) {
            LOGGER.error(String.valueOf(e));
        }
        resp.sendRedirect("/home");
    }

    private void processCart(String productId, String action, Cart cart)
            throws ProductNotFoundException, CartItemNotFoundException
    {
        switch (Action.valueOf(action.toUpperCase())) {
            case ADD -> {
                LOGGER.info("Received request to add product with id: {} to cart", productId);
                cartService.addProductToCart(productId, cart);
            }
            case REMOVE -> {
                LOGGER.info("Received request to remove product with id: {} to cart", productId);
                cartService.removeProductToCart(productId, cart);
            }
            case TOTALLY_REMOVE -> {
                LOGGER.info("Received request to add product with id: {} to cart", productId);
                cartService.removeProductTotallyToCart(productId, cart);
            }
        }
    }

    private Optional<Cart> getCart(HttpServletRequest req) {
        final var currentUser = SecurityContext.getCurrentUser(req);
        return Optional.ofNullable(cartService.getCartByUser(currentUser));
    }
}
