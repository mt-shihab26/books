package com.shihabmahamud.eshoppers.web;

import com.shihabmahamud.eshoppers.dto.ProductDTO;
import com.shihabmahamud.eshoppers.repository.CartItemRepositoryImpl;
import com.shihabmahamud.eshoppers.repository.CartRepositoryImpl;
import com.shihabmahamud.eshoppers.repository.ProductRepositoryImpl;
import com.shihabmahamud.eshoppers.service.CartService;
import com.shihabmahamud.eshoppers.service.CartServiceImpl;
import com.shihabmahamud.eshoppers.service.ProductService;
import com.shihabmahamud.eshoppers.service.ProductServiceImpl;
import com.shihabmahamud.eshoppers.util.SecurityContext;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;
import java.util.Scanner;

@WebServlet("/home")
public class HomeServlet extends HttpServlet {
    private final ProductService productService =
            new ProductServiceImpl(new ProductRepositoryImpl());
    private final CartService cartService = new CartServiceImpl(
            new CartRepositoryImpl(),
            new ProductRepositoryImpl(),
            new CartItemRepositoryImpl()
    );
    private final static Logger LOGGER = LoggerFactory.getLogger(HomeServlet.class);

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse res)
            throws ServletException, IOException {

        LOGGER.info("Serving home page");
        var allProducts = productService.findAllProductSortedByName();
        LOGGER.info("Total product found {}", allProducts.size());

        if (SecurityContext.isAuthenticated(req)) {
            var currentUser = SecurityContext.getCurrentUser(req);
            var cart = cartService.getCartByUser(currentUser);
            req.setAttribute("cart", cart);
        }

        final String orderSuccess = req.getParameter("orderSuccess");
        if (Boolean.parseBoolean(orderSuccess)) {
            req.setAttribute("message", "<strong>Congratulation!</strong>" +
                    " You're order has been placed successfully");
        }

        req.setAttribute("products", allProducts);

        req.getRequestDispatcher("/WEB-INF/home-jstl.jsp")
                .forward(req, res);
    }
}
