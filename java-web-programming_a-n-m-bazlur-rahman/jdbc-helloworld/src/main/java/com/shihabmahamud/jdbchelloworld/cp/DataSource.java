package com.shihabmahamud.jdbchelloworld.cp;

import java.sql.Connection;
import java.sql.SQLException;

public class DataSource {
    private static final JdbcConnectionPool pool = new JdbcConnectionPool();
    public static Connection getConnection() throws SQLException {
        return pool.getConnectionFromPool();
    }
}
