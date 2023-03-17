package com.shihabmahamud.eshoppers.tx;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import javax.inject.Inject;
import java.sql.Connection;
import java.sql.SQLException;

public class TransactionTemplate {
    private final static Logger LOGGER = LoggerFactory
            .getLogger(TransactionTemplate.class);

    @Inject
    private ConnectionHolder connectionHolder;

    private void execute(Transactional transaction) {
        var connection = connectionHolder.getConnection();

        try {
            setAutoCommitFalse(connection);
            transaction.doInTransaction();
            connection.commit();
        } catch (Throwable e) {
            rollback(connection, e);
        } finally {
            setAutoCommitTrue(connection);
        }
    }

    public <T> T execute(CallableTransactional<T> callableTransactional) {
        LOGGER.info("Executing transactions");

        Connection connection = connectionHolder.getConnection();

        try {
            setAutoCommitFalse(connection);
            T result = callableTransactional.doInTransaction();
            connection.commit();
            return result;
        } catch (Throwable e) {
            rollback(connection, e);
            throw  new RuntimeException(e);
        } finally {
            setAutoCommitTrue(connection);
        }
    }


    private void setAutoCommitFalse(Connection connection) throws SQLException {
        connection.setAutoCommit(false);
    }

    private void setAutoCommitTrue(Connection connection) {
        try {
            connection.setAutoCommit(true);
        } catch (SQLException e) {
            LOGGER.info("Unable to set auto commit");
            throw new RuntimeException(e);
        }
    }

    private void rollback(Connection connection, Throwable e) {
        LOGGER.error("Rolling back on application exception from transaction callback", e);
        try {
            connection.rollback();
        } catch (SQLException ex) {
            LOGGER.error("Unable to rollback", ex);
        }
    }
}
