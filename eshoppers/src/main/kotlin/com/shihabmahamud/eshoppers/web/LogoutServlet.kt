package com.shihabmahamud.eshoppers.web

import com.shihabmahamud.eshoppers.util.SecurityContext
import org.slf4j.LoggerFactory
import javax.servlet.annotation.WebServlet
import javax.servlet.http.HttpServlet
import javax.servlet.http.HttpServletRequest
import javax.servlet.http.HttpServletResponse

@WebServlet("/logout")
class LogoutServlet : HttpServlet() {
    override fun doPost(req: HttpServletRequest, resp: HttpServletResponse) {
        LOGGER.info("Logging out")
        SecurityContext.logout(req)
        resp.sendRedirect("/login?logout=true")
    }

    companion object {
        private val LOGGER = LoggerFactory.getLogger(LogoutServlet::class.java)
    }
}