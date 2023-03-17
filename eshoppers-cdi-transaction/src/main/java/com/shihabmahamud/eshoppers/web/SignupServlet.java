package com.shihabmahamud.eshoppers.web;

import com.shihabmahamud.eshoppers.dto.UserDTO;
import com.shihabmahamud.eshoppers.repository.JdbcUserRepositoryImpl;
import com.shihabmahamud.eshoppers.service.UserService;
import com.shihabmahamud.eshoppers.service.UserServiceImpl;
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

@WebServlet("/signup")
public class SignupServlet extends HttpServlet {
    private final Logger LOGGER = LoggerFactory.getLogger(LogoutServlet.class);

    @Inject
    private UserService userService;

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException
    {
        LOGGER.info("serving signup page");
        req.getRequestDispatcher("/WEB-INF/signup.jsp")
                .forward(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp)
            throws ServletException, IOException
    {
        var userDTO = copyParametersTo(req);

        var errors = ValidationUtil.getInstance().validate(userDTO);
        if (errors.size() > 0) {
            req.setAttribute("userDto", userDTO);
            req.setAttribute("errors", errors);
            LOGGER.info("User sent invalid data: {}", userDTO);
            req.getRequestDispatcher("/WEB-INF/signup.jsp").forward(req, resp);
            return;
        }

        if (userService.isNotUniqueUsername(userDTO)) {
            req.setAttribute("userDto", userDTO);
            LOGGER.info("Username: {} is already exits", userDTO.getUsername());
            errors.put("username", "The username already exits");
            req.setAttribute("errors", errors);
            req.getRequestDispatcher("/WEB-INF/signup.jsp").forward(req, resp);
            return;
        }

        LOGGER.info("user is valid, creating ne user with: {}", userDTO);
        userService.saveUser(userDTO);
        resp.sendRedirect("/login");
    }

    private UserDTO copyParametersTo(HttpServletRequest req){
        return new UserDTO(
                req.getParameter("username"),
                req.getParameter("email"),
                req.getParameter("password"),
                req.getParameter("passwordConfirmed"),
                req.getParameter("firstname"),
                req.getParameter("lastname")
        );
    }
}
