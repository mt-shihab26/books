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

        try (var c = DBConnection.tryConnection();
             var p = c.prepareStatement(sql))
        {
            p.setString(1, product.getName());
            p.setString(2, product.getDescription());
            p.setBigDecimal(3, product.getPrice());
            p.setLong(4, product.getVersion());
            p.setTimestamp(5, Timestamp.valueOf(product.getDateCreated()));
            p.setTimestamp(6, Timestamp.valueOf(product.getDateLastUpdated()));
            p.execute();
        } catch (Exception e) {
            throw new RuntimeException("Unable to insert product information in database", e);
        }
    }

    @Override
    public List<Product> findAll() {
        var sql = "SELECT * FROM product;";
        List<Product> products = new ArrayList<>();
        try (var c = DBConnection.tryConnection();
            var p = c.prepareStatement(sql))
        {
            var resultSet = p.executeQuery();
            while (resultSet.next()) {
                Product product = extractProduct(resultSet);
                products.add(product);
            }
        } catch (Exception e) {
            throw new RuntimeException("Unable to insert product information int database", e);
        }
        return products;
    }

    @Override
    public void update(Product product) {
        var sql = """
                UPDATE product
                SET name = ?,
                    description = ?,
                    price = ?,
                    version = ?,
                    date_last_updated = ?
                WHERE id = ?
                """;
        try (var c = DBConnection.tryConnection();
             var p = c.prepareStatement(sql))
        {
            p.setString(1, product.getName());
            p.setString(2, product.getDescription());
            p.setBigDecimal(3, product.getPrice());
            p.setLong(4, product.getVersion()+1);
            p.setTimestamp(5, Timestamp.valueOf(product.getDateLastUpdated()));
            p.setLong(6, product.getId());
            p.executeUpdate();
        } catch (Exception e) {
            throw new RuntimeException("Unable to insert product information into database", e);
        }
    }

    @Override
    public void delete(Long id) {
        var sql = "DELETE FROM product WHERE id = ? ;";

        try (var c = DBConnection.tryConnection();
             var p = c.prepareStatement(sql))
        {
            p.setLong(1, id);
            p.execute();
        } catch (Exception e) {
            throw new RuntimeException("Unable to insert product information into database", e);
        }
    }

    private Product extractProduct(ResultSet res) throws SQLException {
        return new Product(
            res.getLong("id"),
            res.getString("name"),
            res.getString("description"),
            res.getLong("version"),
            res.getBigDecimal("price"),
            res.getTimestamp("date_created").toLocalDateTime(),
            res.getTimestamp("date_last_updated").toLocalDateTime()
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
