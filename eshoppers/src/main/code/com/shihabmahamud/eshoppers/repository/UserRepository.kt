package com.shihabmahamud.eshoppers.repository

import com.shihabmahamud.eshoppers.domain.User

interface UserRepository {
    fun save(user: User)
    fun findOneByUsername(username: String): User?
    fun findOneByEmail(email: String): User?
}