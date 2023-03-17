package com.shihabmahamud.converter.service;

public class Converter {
    public static Double toFahrenheit(Double celsius) {
        /*
         * f-32/9 = c/5
         * f-32 = c * 9 / 5
         * f = (c * 9 / 5) + 32
         * */
        return (celsius * 9 / 5) + 32;
    }

    public static Double meterToKilometer(Double meter) {
        return meter / 1000;
    }
}

