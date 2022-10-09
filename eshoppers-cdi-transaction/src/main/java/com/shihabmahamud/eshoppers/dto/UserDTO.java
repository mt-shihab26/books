package com.shihabmahamud.eshoppers.dto;

import com.shihabmahamud.eshoppers.util.PasswordEqual;

import javax.validation.constraints.Email;
import javax.validation.constraints.NotEmpty;
import javax.validation.constraints.Size;

@PasswordEqual(
        first = "password",
        second = "passwordConfirmed",
        message = "password and confirm password do not match"
)
public class UserDTO {
    @NotEmpty
    @Size(min = 4, max = 32)
    private String username;

    @NotEmpty
    @Size(min = 4, max = 64)
    @Email
    private String  email;

    @NotEmpty
    @Size(min = 6, max = 24)
    private String  password;

    @NotEmpty
    @Size(min = 6, max = 24)
    private String  passwordConfirmed;

    @NotEmpty
    @Size(min = 1, max = 32)
    private String  firstname;

    @NotEmpty
    @Size(min = 1, max = 32)
    private String  lastname;

    public UserDTO(String username, String email, String password,
                   String passwordConfirmed, String firstname, String lastname) {
        this.username = username;
        this.email = email;
        this.password = password;
        this.passwordConfirmed = passwordConfirmed;
        this.firstname = firstname;
        this.lastname = lastname;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getPasswordConfirmed() {
        return passwordConfirmed;
    }

    public void setPasswordConfirmed(String passwordConfirmed) {
        this.passwordConfirmed = passwordConfirmed;
    }

    public String getFirstname() {
        return firstname;
    }

    public void setFirstname(String firstname) {
        this.firstname = firstname;
    }

    public String getLastname() {
        return lastname;
    }

    public void setLastname(String lastname) {
        this.lastname = lastname;
    }
}
