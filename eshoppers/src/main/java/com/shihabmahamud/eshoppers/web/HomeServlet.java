package com.shihabmahamud.eshoppers.web;

import com.shihabmahamud.eshoppers.repository.DummyProductRepositoryImpl;
import com.shihabmahamud.eshoppers.service.ProductService;
import com.shihabmahamud.eshoppers.service.ProductServiceImpl;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/home")
public class HomeServlet extends HttpServlet {
    private final ProductService productService =
            new ProductServiceImpl(new DummyProductRepositoryImpl());

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse res)
            throws ServletException, IOException {
        if (true) {
            throw new RuntimeException();
        }
        var allProducts = productService.findAllProductSortedByName();

        req.setAttribute("products", allProducts);
        req.setAttribute("age", 17);

        req.getRequestDispatcher("/WEB-INF/home-jstl.jsp")
                .forward(req, res);
    }

}
