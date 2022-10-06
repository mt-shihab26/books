package com.shihabmahamud.jdbchelloworld;

import java.sql.Connection;
import java.sql.SQLException;

public class CreateDatabase {
    public void createDatabase(Connection connection, String dbName) {
        var sql = "create database " + dbName;

        try {
            var statement = connection.createStatement();
            statement.execute(sql);
        } catch (SQLException e) {
            throw new RuntimeException("Unable to create database", e);
        }
    }

    public static void main(String[] args) throws Exception {
        var dbConnection = new DBConnection();
        var createDatabase = new CreateDatabase();
        var connection = dbConnection.tryConnection();
        createDatabase.createDatabase(connection, "jdbcHelloworld");
    }
}
