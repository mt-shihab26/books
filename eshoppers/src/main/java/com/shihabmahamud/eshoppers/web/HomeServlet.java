package com.shihabmahamud.eshoppers.web;

import com.shihabmahamud.eshoppers.repository.ProductRepositoryImpl;
import com.shihabmahamud.eshoppers.service.ProductService;
import com.shihabmahamud.eshoppers.service.ProductServiceImpl;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;


@WebServlet("/home")
public class HomeServlet extends HttpServlet {
    private final ProductService productService =
            new ProductServiceImpl(new ProductRepositoryImpl());
    private final static Logger LOGGER = LoggerFactory.getLogger(HomeServlet.class);

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse res)
            throws ServletException, IOException {

        LOGGER.info("Serving home page");

        var allProducts = productService.findAllProductSortedByName();
        LOGGER.info("Total product found {}", allProducts.size());

        req.setAttribute("products", allProducts);
        req.setAttribute("age", 17);

        req.getRequestDispatcher("/WEB-INF/home-jstl.jsp")
                .forward(req, res);
    }

}
