package com.shihabmahamud.cdi.util;

import javax.enterprise.inject.Default;

@Default
public class MD5PasswordEncryption implements PasswordEncryption {
    public String encrypt(String password) {
        // implement password encryption using MD5
        System.out.println("Inside MD5PasswordEncryption::encrypt()");
        return password;
    }
}
