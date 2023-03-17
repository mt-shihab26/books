package com.shihabmahamud.converter.web;

import com.shihabmahamud.converter.service.Converter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/convert")
public class TemperatureConverterServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse res)
            throws ServletException, IOException {
        req.getRequestDispatcher("/WEB-INF/temperature-convert.jsp")
                .forward(req, res);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse res)
            throws ServletException, IOException {
        PrintWriter writer = res.getWriter();
        String tempInCelsius = req.getParameter("temperature");

        if (tempInCelsius == null || tempInCelsius.length() == 0) {
            writer.println("<p>Error temperature not define!</p>");
            return;
        }

        Double tempInFahrenheit = Converter.toFahrenheit(Double.parseDouble(tempInCelsius));
        req.setAttribute("tempInFahrenheit", tempInFahrenheit);
        req.setAttribute("tempInCelsius", tempInCelsius);

        req.getRequestDispatcher("/WEB-INF/temperature-result.jsp")
                .forward(req, res);
    }
}
