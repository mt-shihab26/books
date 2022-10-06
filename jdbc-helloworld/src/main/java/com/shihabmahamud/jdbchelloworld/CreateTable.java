package com.shihabmahamud.jdbchelloworld;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class CreateTable {
    public static void main(String[] args) throws SQLException {
        Connection connection = null;
        try {
            var createTable = new CreateTable();
            connection = DBConnection.tryConnection();
            createTable.createDatabase(connection);
        } catch (Exception e) {
            throw new RuntimeException(e);
        } finally {
            if (connection != null){
                connection.close();
            }
        }

//        createDatabaseTryWith();
    }

    private void createDatabase(Connection connection) throws SQLException {
        String ddl = """
                CREATE TABLE product (
                      id BIGINT AUTO_INCREMENT PRIMARY KEY,
                      name VARCHAR(100) NOT NULL,
                      description VARCHAR(500) NULL,
                      price DECIMAL NOT NULL,
                      version BIGINT NOT NULL,
                      date_created TIMESTAMP NOT NULL,
                      date_last_updated TIMESTAMP NULL
                );
                """;
        final var statement = connection.createStatement();
        statement.execute(ddl);

        String sql = "SHOW TABLES LIKE 'product';";
        ResultSet resultSet = statement.executeQuery(sql);
        if (resultSet.next()) {
            System.out.println("Table successfully created");
        } else {
            System.out.println("Table creation failed");
        }
        statement.close();
    }

    private static void createDatabaseTryWith() {
        try (Connection connection = DBConnection.tryConnection();
             Statement statement = connection.createStatement())
        {
            String ddl = """
                CREATE TABLE product2 (
                      id BIGINT AUTO_INCREMENT PRIMARY KEY,
                      name VARCHAR(100) NOT NULL,
                      description VARCHAR(500) NULL,
                      price DECIMAL NOT NULL,
                      version BIGINT NOT NULL,
                      date_created TIMESTAMP NOT NULL,
                      date_last_updated TIMESTAMP NULL
                );
                """;
            statement.execute(ddl);

            String sql = "SHOW TABLES LIKE 'product';";

            ResultSet resultSet = statement.executeQuery(sql);
            if (resultSet.next()) {
                System.out.println("Table successfully created");
            } else {
                System.out.println("Table creation failed");
            }

        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }
}
