package com.shihabmahamud.eshoppers.service

import com.shihabmahamud.eshoppers.dto.UserDTO

interface UserService {
    fun saveUser(userDTO: UserDTO)
    fun isNotUniqueUsername(userDTO: UserDTO): Boolean
    fun isNotUniqueEmail(userDTO: UserDTO): Boolean
}