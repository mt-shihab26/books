package com.shihabmahamud.eshoppers.repository;

import com.shihabmahamud.eshoppers.domain.User;
import com.shihabmahamud.eshoppers.jdbc.ConnectionPool;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import javax.inject.Inject;
import javax.sql.DataSource;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Timestamp;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

public class JdbcUserRepositoryImpl implements UserRepository {
    private static final Logger LOGGER = LoggerFactory.getLogger(JdbcProductRepositoryImpl.class);

    private final DataSource ds = ConnectionPool.getInstance().getDataSource();

    @Override
    public User save(User user) {
        LOGGER.info("Creating new user");

        user.setDateCreated(LocalDateTime.now());
        user.setDateLastUpdated(LocalDateTime.now());
        user.setVersion(0L);

        try (var c = ds.getConnection();
             var ps = c.prepareStatement("""
                     INSERT INTO user (username, password, email, first_name,last_name,
                                       version, date_created, date_last_updated)
                     VALUES (?, ?, ?, ?, ?, ?, ?, ?)
                     """))
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
            return findOneByUsername(user.getUsername());
        } catch (SQLException e) {
            LOGGER.info("Unable to save user", e);
            throw new RuntimeException("Unable to save user", e);
        }
    }

    @Override
    public User findOneByUsername(String username) {
        LOGGER.info("Finding one user by username: {}", username);

        try (var c = ds.getConnection();
             var ps = c.prepareStatement("""
                     SELECT * FROM user WHERE username = ?
                     """))
        {
            ps.setString(1, username);

            var users = extractUsers(ps.executeQuery());

            if (users.size() == 0) return null;
            return users.get(0);
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
        user.setId(res.getLong("id"));
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