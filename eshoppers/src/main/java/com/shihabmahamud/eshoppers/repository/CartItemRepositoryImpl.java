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
        var cartItemId = jt.executeInsertQuery(
                SAVE_CART_ITEM,
                cartItem.getQuantity(),
                cartItem.getPrice(),
                cartItem.getProduct().getId(),
                0L,
                cartItem.getDateCreated(),
                cartItem.getDateLastUpdated(),
                cartItem.getCart().getId()
        );

        cartItem.setId(cartItemId);
        return cartItem;
    }

    private static final String UPDATE_CART_ITEM = """
            UPDATE cart_item
            SET quantity = ?,
                price = ?,
                version = ?,
                date_last_updated ?
            WHERE id = ?
            """;
    @Override
    public CartItem update(CartItem cartItem) {
        cartItem.setVersion(cartItem.getVersion() + 1);

        var cartItemUpdate = findOne(cartItem.getId());
        if (cartItemUpdate == null) {
            throw new CartItemNotFoundException("Cart item not found by id, " + cartItem.getId());
        }

        if (cartItem.getVersion() <= cartItemUpdate.getVersion()) {
            throw new OptimisticLockingFailureException("CartItem is already updated by another request");
        }

        cartItemUpdate.setDateLastUpdated(LocalDateTime.now());
        cartItemUpdate.setVersion(cartItem.getVersion());
        cartItemUpdate.setQuantity(cartItem.getQuantity());
        cartItemUpdate.setPrice(cartItem.getPrice());

        jt.updateQuery(UPDATE_CART_ITEM,
                cartItemUpdate.getQuantity(),
                cartItemUpdate.getPrice(),
                cartItemUpdate.getVersion(),
                cartItemUpdate.getDateLastUpdated(),
                cartItemUpdate.getId());

        return cartItemUpdate;
    }

    @Override
    public CartItem findOne(Long id) {
        var cartItems = jt.queryForObject(
                SELECT_CART_ITEM_BY_ID,
                id,
                resultSet -> {
                    var cartItem = new CartItem();
                    cartItem.setId(resultSet.getLong("id"));
                    cartItem.setQuantity(resultSet.getInt("quantity"));
                    cartItem.setPrice(resultSet.getBigDecimal("price"));
                    cartItem.setVersion(resultSet.getLong("version"));
                    cartItem.setDateCreated(resultSet.getTimestamp("date_created").toLocalDateTime());
                    cartItem.setDateLastUpdated(resultSet.getTimestamp("date_last_updated").toLocalDateTime());
                    productRepository.findById(resultSet.getLong("product_id"))
                            .ifPresent(cartItem::setProduct);
                    return cartItem;
                    }
                );

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
            productRepository.findById(productId).ifPresent(cartItem::setProduct);
            return cartItem;
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
