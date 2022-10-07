package com.shihabmahamud.eshoppers.jdbc;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import javax.sql.DataSource;
import java.math.BigDecimal;
import java.sql.*;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

public class JDBCTemplate {
    private static final Logger LOGGER = LoggerFactory.getLogger(JDBCTemplate.class);
    private final DataSource dataSource = ConnectionPool.getInstance().getDataSource();;

    public void updateQuery(String query, Object ...parameters) {
        try (var connection = dataSource.getConnection();
             var statement = connection.prepareStatement(query))
        {
            addParameters(statement, parameters);
            statement.executeUpdate();
        } catch (SQLException e) {
            LOGGER.info("Unable to execute update", e);
            throw new RuntimeException("Unable to execute query for result", e);
        }
    }

    public void query(String query, ThrowableConsumer<ResultSet> consumer) {
        try (var connection = dataSource.getConnection();
             var statement = connection.prepareStatement(query))
        {
            consumer.accept(statement.executeQuery());
        } catch (SQLException e) {
            LOGGER.info("Unable to execute query for result", e);
            throw new RuntimeException("Unable to execute query for result", e);
        }
    }

    public Long executeInsertQuery(String query, Object ...parameters) {
        try (var connection = dataSource.getConnection();
             var statement = connection.prepareStatement(query, Statement.RETURN_GENERATED_KEYS))
        {
            addParameters(statement, parameters);
            final int affectedRows = statement.executeUpdate();
            if (affectedRows == 0) {
                throw new SQLException("Creating user failed, no rows affected.");
            }

            try (ResultSet keys = statement.getGeneratedKeys()) {
                if (keys.next()) {
                    return keys.getLong(1);
                } else {
                    throw new SQLException("Creating user failed, not ID obtained.");
                }
            }

        } catch (SQLException e) {
            LOGGER.error("Unable to insert query", e);
            throw new RuntimeException(e);
        }
    }

    public <E> List<E> queryForObject(String query, ObjectRowMapper<E> objectRowMapper ) {
        try (var connection = dataSource.getConnection();
             var statement = connection.prepareStatement(query))
        {
            var resultSet = statement.executeQuery(query);
            List<E> listOfE = new ArrayList<>();
            while (resultSet.next()) {
                listOfE.add(objectRowMapper.mapRowToObject(resultSet));
            }
            return listOfE;
        } catch (SQLException e) {
            LOGGER.info("Unable to execute query for result", e);
            throw new RuntimeException("Unable to execute query for result", e);
        }
    }

    public <E> List<E> queryForObject(String query, Object param, ObjectRowMapper<E> objectRowMapper) {
        try (var connection = dataSource.getConnection();
             var statement = connection.prepareStatement(query))
        {
            addParameters(statement, new Object[]{param});
            var resultSet = statement.executeQuery();
            List<E> listOfE = new ArrayList<>();

            while (resultSet.next()) {
                listOfE.add(objectRowMapper.mapRowToObject(resultSet));
            }
            return listOfE;
        } catch (SQLException e) {
            LOGGER.info("Unable to execute query for result", e);
            throw new RuntimeException("Unable to execute query for result", e);
        }
    }

    public void deleteById(String query, Long id) {
        try (var connection = dataSource.getConnection();
             var statement = connection.prepareStatement(query))
        {
            statement.setLong(1, id);
            statement.execute();
        } catch (SQLException e) {
            LOGGER.info("Unable to execute delete by id: {}", id, e);
            throw new RuntimeException("Unable to execute delete", e);
        }
    }

    private void addParameters(PreparedStatement s, Object[] ps) throws SQLException {
        int idx = 1;
        for (Object p : ps) {
            if (p instanceof String) {
                s.setString(idx, (String) p);
            } else if (p instanceof Integer) {
                s.setInt(idx, (Integer) p);
            } else if (p instanceof Long) {
                s.setLong(idx, (Long) p);
            }  else if (p instanceof Float) {
                s.setFloat(idx, (Float) p);
            } else if (p instanceof Double) {
                s.setDouble(idx, (Double) p);
            } else if (p instanceof LocalDateTime) {
                s.setTimestamp(idx, Timestamp.valueOf(((LocalDateTime) p)));
            } else if (p instanceof Blob) {
                s.setBlob(idx, (Blob) p);
            } else if (p instanceof BigDecimal) {
                s.setBigDecimal(idx, (BigDecimal) p);
            } else if (p instanceof Boolean) {
                s.setBoolean(idx, (Boolean) p);
            }
            idx++;
        }
    }
}
