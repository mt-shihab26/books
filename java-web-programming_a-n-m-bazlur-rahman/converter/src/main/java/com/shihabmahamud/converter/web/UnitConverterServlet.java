package com.shihabmahamud.converter.web;

import com.shihabmahamud.converter.service.Converter;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/meter-to-kilometer")
public class UnitConverterServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse res)
            throws ServletException, IOException {
        req.getRequestDispatcher("/WEB-INF/meter-to-kilometer.jsp")
                .forward(req, res);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse res)
            throws ServletException, IOException {
        String meter = req.getParameter("meter");
        Double kilometer = Converter.meterToKilometer(Double.parseDouble(meter));

        req.setAttribute("meter", meter);
        req.setAttribute("kilometer", kilometer);

        req.getRequestDispatcher("/WEB-INF/meter-to-kilometer-result.jsp")
                .forward(req, res);
    }
}
