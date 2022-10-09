package com.shihabmahamud.cdi;

@Sha256
public class Sha256PasswordEncryption implements PasswordEncryption{
    @Override
    public String encrypt(String password) {
        // implement password encryption using SHA 256
        System.out.println("Inside Sha256PasswordEncryption::encrypt()");
        return password;
    }
}
