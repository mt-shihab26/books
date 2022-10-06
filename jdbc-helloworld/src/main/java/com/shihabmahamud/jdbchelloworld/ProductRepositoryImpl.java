package com.shihabmahamud.jdbchelloworld;


import java.math.BigDecimal;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Timestamp;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

public class ProductRepositoryImpl implements ProductRepository {
    @Override
    public void save(Product product) {
        var sql = """ 
            INSERT INTO product (
                name,
                description,
                price,
                version,
                date_created,
                date_last_updated
            )
            VALUES (?, ?, ?, ?, ?, ?)""";

        try (var connection = DBConnection.tryConnection();
             var pstmnt = connection.prepareStatement(sql))
        {
            pstmnt.setString(1, product.getName());
            pstmnt.setString(2, product.getDescription());
            pstmnt.setBigDecimal(3, product.getPrice());
            pstmnt.setLong(4, product.getVersion());
            pstmnt.setTimestamp(5, Timestamp.valueOf(product.getDateCreated()));
            pstmnt.setTimestamp(6, Timestamp.valueOf(product.getDateLastUpdated()));
            pstmnt.execute();
        } catch (Exception e) {
            throw new RuntimeException("Unable to insert product information in database", e);
        }
    }

    @Override
    public List<Product> findAll() {
        var sql = "SELECT * FROM product;";
        List<Product> products = new ArrayList<>();
        try (var connection = DBConnection.tryConnection();
            var pstmnt = connection.prepareStatement(sql))
        {
            var resultSet = pstmnt.executeQuery();
            while (resultSet.next()) {
                Product product = extractProduct(resultSet);
                products.add(product);
            }
        } catch (Exception e) {
            throw new RuntimeException("Unable to insert product information int database", e);
        }
        return products;
    }

    private Product extractProduct(ResultSet resultSet) throws SQLException {
        return new Product(
            resultSet.getLong("id"),
            resultSet.getString("name"),
            resultSet.getString("description"),
            resultSet.getLong("version"),
            resultSet.getBigDecimal("price"),
            resultSet.getTimestamp("date_created").toLocalDateTime(),
            resultSet.getTimestamp("date_last_updated").toLocalDateTime()
        );
    }

    public static void main(String[] args) {
        var product = new Product(
                "Google Pixel 4 xl",
                "Google Pixel 4 XL - Oh So Orange - 128GB - Unlocked",
                0L,
                BigDecimal.valueOf(999.00),
                LocalDateTime.now(),
                LocalDateTime.now()
        );
        ProductRepository productRepository = new ProductRepositoryImpl();
        productRepository.save(product);
        var products = productRepository.findAll();
        System.out.println(products);
    }
}
