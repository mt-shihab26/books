package com.shihabmahamud.eshoppers.web

import com.shihabmahamud.eshoppers.dto.UserDTO
import com.shihabmahamud.eshoppers.repository.UserRepositoryImpl
import com.shihabmahamud.eshoppers.service.UserService
import com.shihabmahamud.eshoppers.service.UserServiceImpl
import com.shihabmahamud.eshoppers.util.ValidationUtil
import com.shihabmahamud.eshoppers.util.Validations
import org.slf4j.LoggerFactory
import javax.servlet.annotation.WebServlet
import javax.servlet.http.HttpServlet
import javax.servlet.http.HttpServletRequest
import javax.servlet.http.HttpServletResponse
import javax.validation.Validation

@WebServlet("/signup")
class SignupServlet : HttpServlet() {
    private val userService: UserService = UserServiceImpl(UserRepositoryImpl())

    override fun doGet(req: HttpServletRequest, resp: HttpServletResponse) {
        LOGGER.info("serving signup page")
        req.getRequestDispatcher("/WEB-INF/signup.jsp")
            .forward(req, resp)
    }

    override fun doPost(req: HttpServletRequest, resp: HttpServletResponse) {
        val userDTO = copyParametersTo(req)

        val errors = ValidationUtil.getInstance().validate(userDTO)
        if (errors.isNotEmpty()) {
            req.setAttribute("userDto", userDTO)
            req.setAttribute("errors", errors)
            LOGGER.info("User sent invalid data: {}", userDTO.toString())
            req.getRequestDispatcher("/WEB-INF/signup.jsp").forward(req, resp)
            return
        }

        if (userService.isNotUniqueUsername(userDTO)) {
            req.setAttribute("userDto", userDTO)
            LOGGER.info("Username: {} is already exits", userDTO.username)
            errors["username"] = "The username already exits"
            req.setAttribute("errors", errors)
            req.getRequestDispatcher("/WEB-INF/signup.jsp").forward(req, resp)
            return
        }

        LOGGER.info("user is valid, creating ne user with: {}", userDTO)
        userService.saveUser(userDTO)
        resp.sendRedirect("/home")
    }

    private fun copyParametersTo(req: HttpServletRequest): UserDTO {
        return UserDTO(
            req.getParameter("username"),
            req.getParameter("email"),
            req.getParameter("password"),
            req.getParameter("passwordConfirmed"),
            req.getParameter("firstname"),
            req.getParameter("lastname")
        )
    }

    private fun validate(userDTO: UserDTO): Map<String, String> {
        val violations = Validation
            .buildDefaultValidatorFactory()
            .validator
            .validate(userDTO)
        val errors = HashMap<String, String>()

        for (violation in violations) {
            val path = violation.propertyPath.toString()
            if (errors.containsKey(path)) {
                val errorMsg = errors[path]
                errors[path] = errorMsg + "<br/>" + violation.message
            }
            else {
                errors[path] = violation.message
            }
        }
        return errors
    }

    private fun isValid(userDTO: UserDTO): Boolean {
        val violations = Validation
            .buildDefaultValidatorFactory()
            .validator
            .validate(userDTO)
        println(violations)
        return violations.size == 0
    }

    private fun isValidOwn(userDTO: UserDTO): Boolean {
//        val user: User? = userService.findUserByUsername(userDTO.username)
//        if (user != null) return false
        if (!Validations.strLen(userDTO.username, 4, 32))
            return false

        if (!Validations.strLen(userDTO.firstname, 1, 32))
            return false

        if (!Validations.strLen(userDTO.lastname, 1, 32))
            return false

        if (userDTO.password != userDTO.passwordConfirmed)
            return false
        if (!Validations.strLen(userDTO.password, 6, 24))
            return false

        if (!Validations.email(userDTO.email))
            return false

        return true
    }

    companion object {
        private val LOGGER = LoggerFactory
            .getLogger(SignupServlet::class.java)
    }
}