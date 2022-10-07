package com.shihabmahamud.eshoppers.repository;

import com.shihabmahamud.eshoppers.domain.Product;
import com.shihabmahamud.eshoppers.jdbc.ConnectionPool;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import javax.sql.DataSource;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class JdbcProductRepositoryImpl implements ProductRepository {
    private static final Logger LOGGER = LoggerFactory.getLogger(JdbcProductRepositoryImpl.class);
    private final DataSource dataSource = ConnectionPool.getInstance().getDataSource();
    private static final String SELECT_ALL_PRODUCTS = "SELECT * FROM product";
    private static final String SELECT_PRODUCT_BY_ID = "SELECT * FROM product WHERE id = ?";
    @Override
    public List<Product> findAllProduct() {
        try (var c = dataSource.getConnection();
             var ps = c.prepareStatement(SELECT_ALL_PRODUCTS))
        {
            var resultSet = ps.executeQuery();
            return extractProducts(resultSet);
        } catch (SQLException e) {
            LOGGER.info("Unable to fetch products from database", e);
        }
        return null;
    }

    @Override
    public Product findById(Long id) {
        try (var c = dataSource.getConnection();
             var ps = c.prepareStatement(SELECT_PRODUCT_BY_ID))
        {
            ps.setLong(1, id);
            var products = extractProducts(ps.executeQuery());
            if (products.size() > 0) {
                return products.get(0);
            }
        } catch (SQLException e) {
            LOGGER.info("Unable to fetch product by id: {} ", id, e);
        }
        return null;
    }

    private List<Product> extractProducts(ResultSet res) throws SQLException {
        List<Product> products = new ArrayList<>();
        while (res.next()) {
            products.add(extractProduct(res));
        }
        return products;
    }

    private Product extractProduct(ResultSet res) throws SQLException {
        return new Product(
                res.getLong("id"),
                res.getString("name"),
                res.getString("description"),
                res.getBigDecimal("price"),
                Double.valueOf(String.valueOf(res.getBigDecimal("rating"))),
                res.getLong("version"),
                res.getTimestamp("date_created").toLocalDateTime(),
                res.getTimestamp("date_last_updated").toLocalDateTime()
        );
    }
}
