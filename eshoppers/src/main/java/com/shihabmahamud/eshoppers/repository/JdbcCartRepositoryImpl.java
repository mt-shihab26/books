package com.shihabmahamud.eshoppers.repository;

import com.shihabmahamud.eshoppers.domain.Cart;
import com.shihabmahamud.eshoppers.domain.CartItem;
import com.shihabmahamud.eshoppers.domain.Order;
import com.shihabmahamud.eshoppers.domain.User;
import com.shihabmahamud.eshoppers.exceptions.CartNotFoundException;
import com.shihabmahamud.eshoppers.exceptions.OptimisticLockingFailureException;
import com.shihabmahamud.eshoppers.jdbc.ConnectionPool;
import com.shihabmahamud.eshoppers.web.HomeServlet;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import javax.sql.DataSource;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.Timestamp;
import java.time.LocalDateTime;
import java.util.LinkedHashSet;
import java.util.Set;

public class JdbcCartRepositoryImpl implements CartRepository{
    private final static Logger LOGGER = LoggerFactory.getLogger(HomeServlet.class);
    private final OrderRepository orderRepository = new OrderRepositoryImpl();
    private final ProductRepository productRepository = new JdbcProductRepositoryImpl();
    private final DataSource ds = ConnectionPool.getInstance().getDataSource();

    public static final String FIND_BY_USER = """
            SELECT * FROM cart WHERE user_id = ?
            """;


    @Override
    public Cart findByUser(User currentUser) {
        try (var c = ds.getConnection();
             var ps = c.prepareStatement(FIND_BY_USER))
        {

            ps.setLong(1, currentUser.getId());

            var res = ps.executeQuery();
            Cart cart = extractCart(res);
            cart.setUser(currentUser);

            Set<CartItem> allCartItems = findAllCartItemsForCart(cart.getId());
            if (allCartItems != null) {
                cart.setCartItems(allCartItems);
            }

            var orders = orderRepository.findOrderByUser(currentUser);
            if (orders == null) return cart;

            for (Order order : orders) {
                if (order.getCart().equals(cart)) {
                    return null;
                }
             }
            return cart;
        } catch (SQLException e) {
            LOGGER.debug("Unable to find Cart by given currentUser");
            return null;
        }
    }

    private Cart extractCart(ResultSet res) throws SQLException {
        if (res.next()) {
            var cart = new Cart();
            cart.setId(res.getLong("id"));
            cart.setTotalPrice(res.getBigDecimal("total_price"));
            cart.setTotalItem(res.getInt("total_item"));
            cart.setVersion(res.getLong("version"));
            cart.setDateLastUpdated(res.getTimestamp("date_last_updated").toLocalDateTime());
            cart.setDateCreated(res.getTimestamp("date_created").toLocalDateTime());
            return cart;
        } {
            throw new SQLException("Unable to find cart item for jdbc resultSet");
        }
    }

    public static final String FIND_ALL_CART_ITEMS = "select *" +
            " from cart_item c" +
            " where c.cart_id = ?";

    private Set<CartItem> findAllCartItemsForCart(Long cartId) {
        try (var c = ds.getConnection();
             var ps = c.prepareStatement(FIND_ALL_CART_ITEMS))
        {
            ps.setLong(1, cartId);
            var res = ps.executeQuery();
            return extractCartItems(res);
        } catch (SQLException e) {
            LOGGER.debug("Unable to find all cartItem for given cart id");
            return null;
        }
    }

    private Set<CartItem> extractCartItems(ResultSet resultSet) throws SQLException {
        Set<CartItem> cartItems = new LinkedHashSet<>();
        while (resultSet.next()) {
            var cartItem = new CartItem();
            cartItem.setId(resultSet.getLong("id"));
            cartItem.setQuantity(resultSet.getInt("quantity"));
            cartItem.setPrice(resultSet.getBigDecimal("price"));
            cartItem.setVersion(resultSet.getLong("version"));
            cartItem.setDateCreated(resultSet.getTimestamp("date_created").toLocalDateTime());
            cartItem.setDateLastUpdated(resultSet.getTimestamp("date_last_updated").toLocalDateTime());

            var productId = resultSet.getLong("product_id");
            var product = productRepository.findById(productId);

            if (product != null) {
                cartItem.setProduct(product);
            }
            cartItems.add(cartItem);
        }
        return cartItems;
    }

    private static final String INSERT_CART = "INSERT INTO cart (" +
            " total_price, " +
            " total_item, " +
            " version, " +
            " date_created, " +
            " date_last_updated, " +
            " user_id ) VALUES (?,?,?,?,?,?)";

    @Override
    public Cart save(Cart cart) {
        cart.setDateCreated(LocalDateTime.now());
        cart.setDateLastUpdated(LocalDateTime.now());
        cart.setVersion(0L);

        try (var c = ds.getConnection();
             var ps = c.prepareStatement(INSERT_CART, Statement.RETURN_GENERATED_KEYS))
        {
            ps.setBigDecimal(1, cart.getTotalPrice());
            ps.setInt(2, cart.getTotalItem());
            ps.setLong(3, cart.getVersion());
            ps.setTimestamp(4, Timestamp.valueOf(cart.getDateCreated()));
            ps.setTimestamp(5, Timestamp.valueOf(cart.getDateLastUpdated()));
            ps.setLong(6, cart.getUser().getId());

            final int affectedRows = ps.executeUpdate();

            if (affectedRows == 0) {
                LOGGER.debug("Creating user failed, no rows affected.");
                throw new SQLException();
            }
            try (ResultSet generatedKeys = ps.getGeneratedKeys()) {
                if (generatedKeys.next()) {
                    Long cartId = generatedKeys.getLong(1);
                    cart.setId(cartId);
                    return cart;
                } else {
                    LOGGER.debug("Creating user failed, no ID obtained.");
                    throw new SQLException();
                }
            }
        } catch (SQLException e) {
            LOGGER.debug("Unable to find all cartItem for given cart id");
            return null;
        }
    }

    public static final String UPDATE_CART = "UPDATE cart " +
            " SET total_price = ? " +
            ", total_item = ? " +
            ", version = ? " +
            ", date_last_updated = ? WHERE id = ?";

    @Override
    public Cart update(Cart cart) {
        cart.setVersion(cart.getVersion() + 1);

        Cart cartToUpdate = findByCartId(cart.getId());
        if (cartToUpdate == null) {
            throw new CartNotFoundException("Shopping Cart not found by Id " + cart.getId());
        }

        if (cart.getVersion() <= (cartToUpdate.getVersion())) {
            throw new OptimisticLockingFailureException("Shopping cart is already updated by another request");
        }

        cartToUpdate.setTotalPrice(cart.getTotalPrice());
        cartToUpdate.setTotalItem(cart.getTotalItem());
        cartToUpdate.setVersion(cart.getVersion());
        cartToUpdate.setDateLastUpdated(LocalDateTime.now());
        cartToUpdate.setCartItems(cart.getCartItems());

        try (var c = ds.getConnection();
             var ps = c.prepareStatement(UPDATE_CART))
        {
            ps.setBigDecimal(1, cartToUpdate.getTotalPrice());
            ps.setInt(2, cartToUpdate.getTotalItem());
            ps.setLong(3, cartToUpdate.getVersion());
            ps.setTimestamp(4, Timestamp.valueOf(cartToUpdate.getDateLastUpdated()));
            ps.setLong(5, cartToUpdate.getId());

            ps.executeUpdate();

            return cartToUpdate;
        } catch (SQLException e) {
            LOGGER.debug("Unable to find all cartItem for given cart id");
            return null;
        }
    }

    public static final String FIND_BY_ID = "SELECT id, " +
            " total_price, " +
            " total_item, " +
            " version, " +
            " date_created, " +
            " date_last_updated, " +
            " user_id FROM cart WHERE id = ? ";

    private Cart findByCartId(Long cartId) {
        try (var c = ds.getConnection();
             var ps = c.prepareStatement(FIND_BY_ID))
        {
            ps.setLong(1, cartId);

            var res = ps.executeQuery();
            return extractCart(res);
        } catch (SQLException e) {
            LOGGER.debug("Unable to find all cartItem for given cart id");
            return null;
        }
    }
}
