package com.shihabmahamud.jdbchelloworld;

import java.sql.Connection;
import java.sql.DriverManager;

public class DBConnection {
    private static final String URL = "jdbc:mysql://localhost:3306/jdbcHelloworld";
    private static final String USER = "root";
    private static final String PASSWORD = "2611";

    public static Connection tryConnection() throws Exception {
        return DriverManager.getConnection(URL, USER, PASSWORD);
    }

    public static void main(String[] args) throws Exception {
        var connection = tryConnection();
        if (connection.isValid(2)) {
            System.out.println("The attempt to Connection was a SUCCESS");
        } else {
            System.out.println("The attempt to Connection was FAILED");
        }
    }
}
