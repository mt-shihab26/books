package com.shihabmahamud.eshoppers.util;

import java.util.regex.Pattern;

public class Validations {
    Boolean email(String email) {
        if (email == null) return false;
        final var emailRegex = "^[a-zA-Z0-9_+&*-]+(?:\\." +
                "[a-zA-Z0-9_+&*-]+)*@" +
                "(?:[a-zA-Z0-9-]+\\.)+[a-z" +
                "A-Z]{2,7}$";
        final var pat = Pattern.compile(emailRegex);
        return pat.matcher(email).matches();
    }

    Boolean strLen(String str, Integer min, Integer max) {
        if (str.length() < min) return false;
        return str.length() <= max;
    }
}
