package com.shihabmahamud.eshoppers.repository;

import com.shihabmahamud.eshoppers.domain.User;
import com.shihabmahamud.eshoppers.jdbc.ConnectionPool;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import javax.sql.DataSource;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Timestamp;
import java.util.ArrayList;
import java.util.List;

public class JdbcUserRepositoryImpl implements UserRepository {
    private static final Logger LOGGER = LoggerFactory.getLogger(JdbcProductRepositoryImpl.class);
    private final DataSource ds = ConnectionPool.getInstance().getDataSource();
    private final static String SAVE_USER = "INSERT INTO user (" +
            "username, password, " +
            "email, first_name, " +
            "last_name, version, " +
            "date_created, date_last_updated) " +
            "VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
    private final static String SELECT_BY_USERNAME = "SELECT * FROM user WHERE username = ? ";

    @Override
    public void save(User user) {
        try (var c = ds.getConnection();
             var ps = c.prepareStatement(SAVE_USER))
        {
            ps.setString(1, user.getUsername());
            ps.setString(2, user.getPassword());
            ps.setString(3, user.getEmail());
            ps.setString(4, user.getFirstname());
            ps.setString(5, user.getLastname());
            ps.setLong(6, user.getVersion());
            ps.setTimestamp(7, Timestamp.valueOf(user.getDateCreated()));
            ps.setTimestamp(8, Timestamp.valueOf(user.getDateLastUpdated()));
            ps.execute();
        } catch (SQLException e) {
            LOGGER.info("Unable to save user", e);
            throw new RuntimeException("Unable to save user", e);
        }
    }

    @Override
    public User findOneByUsername(String username) {
        try (var c = ds.getConnection();
             var ps = c.prepareStatement(SELECT_BY_USERNAME))
        {
            ps.setString(1, username);

            var users = extractUsers(ps.executeQuery());

            if (users.size() > 0) {
                return users.get(0);
            }
            return null;
        } catch (SQLException e) {
            LOGGER.info("Unable to find user by username: {}", username, e);
            throw new RuntimeException("Unable to find user by username: " + username, e);
        }
    }

    private List<User> extractUsers(ResultSet res) throws SQLException {
        List<User> users = new ArrayList<>();
        while (res.next()) {
            users.add(extractUser(res));
        }
        return  users;
    }

    private User extractUser(ResultSet res) throws SQLException {
        var user = new User();
        user.setUsername(res.getString("username"));
        user.setPassword(res.getString("password"));
        user.setEmail(res.getString("email"));
        user.setFirstname(res.getString("first_name"));
        user.setLastname(res.getString("last_name"));
        user.setVersion(res.getLong("version"));
        user.setDateCreated(res.getTimestamp("date_created").toLocalDateTime());
        user.setDateLastUpdated(res.getTimestamp("date_last_updated").toLocalDateTime());
        return user;
    }
}