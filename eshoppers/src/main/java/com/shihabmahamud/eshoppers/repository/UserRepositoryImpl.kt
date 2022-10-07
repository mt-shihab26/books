package com.shihabmahamud.eshoppers.repository

import com.shihabmahamud.eshoppers.domain.User
import com.shihabmahamud.eshoppers.web.HomeServlet
import org.slf4j.LoggerFactory
import java.util.concurrent.CopyOnWriteArraySet

class UserRepositoryImpl : UserRepository {
    override fun save(user: User) {
        USERS.add(user)
        LOGGER.debug(USERS.toString())
    }

    override fun findOneByUsername(username: String): User? {
        val user = USERS
            .stream()
            .filter { user: User? -> user!!.username == username }
            .findFirst()

        if (!user.isPresent)
            return null

        return user.get()
    }

    companion object {
        private val USERS: MutableSet<User?> = CopyOnWriteArraySet()
        private val LOGGER = LoggerFactory.getLogger(HomeServlet::class.java)
    }
}
