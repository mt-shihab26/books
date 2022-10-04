package com.shihabmahamud.eshoppers.service

import com.shihabmahamud.eshoppers.domain.User
import com.shihabmahamud.eshoppers.dto.UserDTO
import com.shihabmahamud.eshoppers.repository.UserRepository

class UserServiceImpl(private val userRepository: UserRepository) : UserService {
    override fun saveUser(userDTO: UserDTO) {
        val encryptedPassword = encryptPassword(userDTO!!.password)
        val user = User(
            userDTO.username,
            userDTO.email,
            encryptedPassword,
            userDTO.firstname,
            userDTO.lastname
        )
        userRepository.save(user)
    }

    override fun isNotUniqueUsername(userDTO: UserDTO): Boolean {
        val user = userRepository.findOneByUsername(userDTO.username)
        return user != null
    }

    override fun isNotUniqueEmail(userDTO: UserDTO): Boolean {
        val user = userRepository.findOneByEmail(userDTO.email)
        return user != null
    }

    private fun encryptPassword(password: String): String {
        return password
    }
}