package com.shihabmahamud.eshoppers.web;

import com.shihabmahamud.eshoppers.repository.JdbcCartItemRepositoryImpl;
import com.shihabmahamud.eshoppers.repository.JdbcCartRepositoryImpl;
import com.shihabmahamud.eshoppers.repository.JdbcProductRepositoryImpl;
import com.shihabmahamud.eshoppers.repository.JdbcUserRepositoryImpl;
import com.shihabmahamud.eshoppers.service.CartService;
import com.shihabmahamud.eshoppers.service.CartServiceImpl;
import com.shihabmahamud.eshoppers.util.SecurityContext;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/checkout")
public class CheckoutServlet extends HttpServlet {
    private static final Logger LOGGER = LoggerFactory.getLogger(CheckoutServlet.class);
    private final CartService cartService = new CartServiceImpl(
            new JdbcCartRepositoryImpl(),
            new JdbcProductRepositoryImpl(),
            new JdbcCartItemRepositoryImpl(),
            new JdbcUserRepositoryImpl()
    );

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException
    {
        LOGGER.info("Serving checkout page");

        var currentUser = SecurityContext.getCurrentUser(req);
        var cart = cartService.getCartByUser(currentUser);
        req.setAttribute("cart", cart);

        req.getRequestDispatcher("/WEB-INF/checkout.jsp").forward(req, resp);
    }
}
