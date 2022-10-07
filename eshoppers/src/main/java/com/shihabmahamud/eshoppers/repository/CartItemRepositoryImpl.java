package com.shihabmahamud.eshoppers.repository;

import com.shihabmahamud.eshoppers.domain.CartItem;
import com.shihabmahamud.eshoppers.exceptions.CartItemNotFoundException;
import com.shihabmahamud.eshoppers.exceptions.OptimisticLockingFailureException;
import com.shihabmahamud.eshoppers.jdbc.ConnectionPool;
import com.shihabmahamud.eshoppers.jdbc.JDBCTemplate;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import javax.sql.DataSource;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.Timestamp;
import java.time.LocalDateTime;

public class CartItemRepositoryImpl implements CartItemRepository {
    private static final Logger LOGGER = LoggerFactory.getLogger(ProductRepositoryImpl.class);
    private final DataSource ds = ConnectionPool.getInstance().getDataSource();
    private final ProductRepository productRepository = new ProductRepositoryImpl();
    private final JDBCTemplate jt = new JDBCTemplate();

    private static final String UPDATE_CART_ITEM = """
            UPDATE cart_item
            SET quantity = ?,
                price = ?,
                version = ?,
                date_last_updated ?
            WHERE id = ?
            """;
    private static final String SELECT_CART_ITEM_BY_ID = "SELECT * FROM cart_item WHERE id = ?";
    private static final String DELETE_CART_ITEM = "DELETE FROM cart_item WHERE id = ?";

    private static final String SAVE_CART_ITEM = """
            INSERT INTO cart_item (
                quantity,
                price,
                product_id,
                version,
                date_created,
                date_last_updated,
                cart_id)
            VALUES (?, ?, ?, ?, ?, ?, ?)
            """;

    @Override
    public CartItem save(CartItem cartItem) {
//        var cartItemId = jt.executeInsertQuery(
//                SAVE_CART_ITEM,
//                cartItem.getQuantity(),
//                cartItem.getPrice(),
//                cartItem.getProduct().getId(),
//                0L,
//                cartItem.getDateCreated(),
//                cartItem.getDateLastUpdated(),
//                cartItem.getCart().getId()
//        );
//
//        cartItem.setId(cartItemId);
//        return cartItem;

        try (var c = ds.getConnection();
             var ps = c.prepareStatement(SAVE_CART_ITEM, Statement.RETURN_GENERATED_KEYS))
        {
            ps.setLong(1, cartItem.getProduct().getId());
            ps.setInt(2, cartItem.getQuantity());
            ps.setBigDecimal(3, cartItem.getPrice());
            ps.setLong(4, cartItem.getVersion());
            ps.setTimestamp(5, Timestamp.valueOf(cartItem.getDateCreated()));
            ps.setTimestamp(6, Timestamp.valueOf(cartItem.getDateLastUpdated()));

            int affectedRows = ps.executeUpdate();
            if (affectedRows == 0) {
                throw new SQLException("Creating user failed, not row affected.");
            }
            try (ResultSet generatedKeys = ps.getGeneratedKeys()) {
                if (generatedKeys.next()) {
                    Long carItemId = generatedKeys.getLong(1);
                    cartItem.setId(carItemId);
                    return cartItem;
                } else {
                    throw new SQLException("Creating user failed, no id obtained.");
                }
            }
        } catch (SQLException e) {
            LOGGER.info("Unable to insert cart item in database: {}", cartItem, e);
            throw new RuntimeException();
        }
    }


    @Override
    public CartItem update(CartItem cartItem) {
        cartItem.setVersion(cartItem.getVersion() + 1);
        var cartItemToUpdate = findOne(cartItem.getId());
        if (cartItemToUpdate == null) {
            throw new CartItemNotFoundException("Cart item not found by id" + cartItem.getId());
        }

        if (cartItem.getVersion() <= cartItemToUpdate.getVersion()) {
            throw new OptimisticLockingFailureException("CartItem is already updated by another request");
        }

        cartItemToUpdate.setDateLastUpdated(LocalDateTime.now());
        cartItemToUpdate.setVersion(cartItem.getVersion());
        cartItemToUpdate.setProduct(cartItem.getProduct());
        cartItemToUpdate.setQuantity(cartItem.getQuantity());
        cartItemToUpdate.setPrice(cartItem.getPrice());

        try (var c = ds.getConnection();
             var ps = c.prepareStatement(UPDATE_CART_ITEM))
        {
            ps.setInt(1, cartItemToUpdate.getQuantity());
            ps.setBigDecimal(2, cartItemToUpdate.getPrice());
            ps.setLong(3, cartItemToUpdate.getVersion());
            ps.setTimestamp(4, Timestamp.valueOf(cartItemToUpdate.getDateLastUpdated()));
            ps.setLong(5, cartItemToUpdate.getId());

            ps.executeUpdate();
        } catch (SQLException e) {
            LOGGER.info("Unable to update cart time: {}", cartItem, e);
            throw new RuntimeException("Unable to update cartItem", e);
        }
        return cartItemToUpdate;
    }

    @Override
    public CartItem findOne(Long id) {
        try (var c = ds.getConnection();
             var ps = c.prepareStatement(SELECT_CART_ITEM_BY_ID))
        {
            ps.setLong(1, id);
            var res = ps.executeQuery();
            return extractCartItem(res);
        } catch (SQLException e) {
            return null;
        }
    }

    private CartItem extractCartItem(ResultSet res) throws SQLException {
        if (res.next()) {
            CartItem cartItem = new CartItem();
            cartItem.setId(res.getLong("id"));
            cartItem.setQuantity(res.getInt("quantity"));
            cartItem.setPrice(res.getBigDecimal("price"));
            cartItem.setVersion(res.getLong("version"));
            cartItem.setDateCreated(res.getTimestamp("date_created").toLocalDateTime());
            cartItem.setDateLastUpdated(res.getTimestamp("date_last_updated").toLocalDateTime());

            var productId = res.getLong("product_id");
            var product = productRepository.findById(productId);
            if (product == null) {
                throw new SQLException("Unable find product by the id: {}", String.valueOf(productId));
            }
            cartItem.setProduct(product);
        } {
            throw new SQLException("Unable to find cart item for jdbc resultSet");
        }
    }

    @Override
    public void remove(CartItem cartItem) {
        try (var c = ds.getConnection();
             var ps = c.prepareStatement(DELETE_CART_ITEM)
        )
        {
            ps.setLong(1, cartItem.getId());
            ps.execute();
        } catch (SQLException e) {
            LOGGER.info("Unable to delete cartItem by id: {}", cartItem.getId(), e);
            throw new RuntimeException("Unable to delete cartItem", e);
        }
    }
}
