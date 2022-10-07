package com.shihabmahamud.eshoppers.web;

import com.shihabmahamud.eshoppers.dto.ProductDTO;
import com.shihabmahamud.eshoppers.repository.*;
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

@WebServlet("/home")
public class HomeServlet extends HttpServlet {
    private static final Logger LOGGER = LoggerFactory.getLogger(HomeServlet.class);

    private final ProductService productService
            = new ProductServiceImpl(new JdbcProductRepositoryImpl());

    private final CartService cartService
            = new CartServiceImpl(new CartRepositoryImpl(),
            new JdbcProductRepositoryImpl(),
            new CartItemRepositoryImpl());

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException {
        LOGGER.info("Serving home page");

        final String attribute = req.getParameter("orderSuccess");

        if (Boolean.parseBoolean(attribute)) {
            req.setAttribute("message", "<strong>Congratulation!</strong> You're order has been placed successfully. ");
        }

        List<ProductDTO> allProducts = productService.findAllProductSortedByName();
        LOGGER.info("Total product found {}", allProducts.size());

        if (SecurityContext.isAuthenticated(req)) {
            var currentUser = SecurityContext.getCurrentUser(req);
            var cart = cartService.getCartByUser(currentUser);
            req.setAttribute("cart", cart);
        }

        req.setAttribute("products", allProducts);

        req.getRequestDispatcher("/WEB-INF/home-jstl.jsp")
                .forward(req, resp);
    }
}
