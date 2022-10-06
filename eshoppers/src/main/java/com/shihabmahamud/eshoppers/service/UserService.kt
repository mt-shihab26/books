package com.shihabmahamud.eshoppers.service

import com.shihabmahamud.eshoppers.domain.User
import com.shihabmahamud.eshoppers.dto.LoginDTO
import com.shihabmahamud.eshoppers.dto.UserDTO

interface UserService {
    fun saveUser(userDTO: UserDTO)
    fun isNotUniqueUsername(userDTO: UserDTO): Boolean
    fun isNotUniqueEmail(userDTO: UserDTO): Boolean
    fun verifyUser(loginDTO: LoginDTO): User
}