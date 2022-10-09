package com.shihabmahamud.eshoppers.web;

import com.shihabmahamud.eshoppers.dto.ShippingAddressDTO;
import com.shihabmahamud.eshoppers.exceptions.CartItemNotFoundException;
import com.shihabmahamud.eshoppers.repository.*;
import com.shihabmahamud.eshoppers.service.*;
import com.shihabmahamud.eshoppers.util.SecurityContext;
import com.shihabmahamud.eshoppers.util.ValidationUtil;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import javax.inject.Inject;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.util.List;

@WebServlet("/order")
public class OrderServlet extends HttpServlet {
    private static final Logger LOGGER = LoggerFactory.getLogger(OrderServlet.class);

    @Inject
    private CartService cartService;

    @Inject
    private OrderService orderService;

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException
    {
        addCartToUi(req);
        req.setAttribute("countries", getCountries());
        req.getRequestDispatcher("/WEB-INF/order.jsp").forward(req, resp);
    }

    private void addCartToUi(HttpServletRequest req) {
        if (SecurityContext.isAuthenticated(req)) {
            var currentUser = SecurityContext.getCurrentUser(req);
            var cart = cartService.getCartByUser(currentUser);
            req.setAttribute("cart", cart);
        }
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException
    {
        LOGGER.info("Handle order request form");
        var shippingAddress = copyParametersTo(req);

        var errors = ValidationUtil
                .getInstance()
                .validate(shippingAddress);

        if (!errors.isEmpty()) {
            req.setAttribute("countries", getCountries());
            req.setAttribute("errors", errors);
            req.setAttribute("shippingAddress", shippingAddress);
            req.getRequestDispatcher("/WEB-INF/order.jsp")
                    .forward(req, resp);
            return;
        }

        try {
            orderService.processOrder(shippingAddress, SecurityContext.getCurrentUser(req));
        } catch (CartItemNotFoundException e) {
            LOGGER.error(String.valueOf(e));
        }
        resp.sendRedirect("/home?orderSuccess=true");
    }

    private List<String> getCountries() {
        return List.of("Bangladesh", "Switzerland", "Japan", "USA", "Canada");
    }

    private ShippingAddressDTO copyParametersTo(HttpServletRequest req) {
        return new ShippingAddressDTO(
                req.getParameter("address"),
                req.getParameter("address2"),
                req.getParameter("state"),
                req.getParameter("zip"),
                req.getParameter("country"),
                req.getParameter("mobileNumber")
        );
    }
}
