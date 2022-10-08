package com.shihabmahamud.eshoppers.repository;

import com.shihabmahamud.eshoppers.domain.Cart;
import com.shihabmahamud.eshoppers.domain.CartItem;
import com.shihabmahamud.eshoppers.domain.User;
import com.shihabmahamud.eshoppers.exceptions.CartNotFoundException;
import com.shihabmahamud.eshoppers.exceptions.OptimisticLockingFailureException;
import com.shihabmahamud.eshoppers.jdbc.ConnectionPool;
import com.shihabmahamud.eshoppers.jdbc.JDBCTemplate;
import com.shihabmahamud.eshoppers.web.HomeServlet;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import javax.sql.DataSource;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.Timestamp;
import java.time.LocalDateTime;
import java.util.*;

public class JdbcCartRepositoryImpl implements CartRepository {
    private final static Logger LOGGER = LoggerFactory.getLogger(HomeServlet.class);
    private final ProductRepository productRepository = new JdbcProductRepositoryImpl();
    private final DataSource ds = ConnectionPool.getInstance().getDataSource();
    private final JDBCTemplate jt = new JDBCTemplate();

    private static final String FIND_BY_USER = "SELECT c.*" +
            " FROM cart c" +
            "         INNER JOIN user u on (c.user_id = u.id)" +
            " WHERE u.id = ? " +
            " AND (c.id not in (select cart_id from `order`))";
    @Override
    public Cart findByUser(User currentUser) {
        var carts = jt.queryForObject(FIND_BY_USER, currentUser.getId(),
                resultSet -> {
                    var cart = extractCart(resultSet);
                    var allCartItems = findAllCartItemsForCart(cart.getId());
                    cart.getCartItems().addAll(allCartItems);
                    return cart;
                }
        );
        if (carts.size() == 0)
            return null;
        return carts.get(0);
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

    private static final String UPDATE_CART = "UPDATE cart " +
            " SET total_price = ? " +
            ", total_item = ? " +
            ", version = ? " +
            ", date_last_updated = ? WHERE id = ?";
    @Override
    public void update(Cart cart) {
        cart.setVersion(cart.getVersion() + 1);

        Cart cartToUpdate = findOne(cart.getId());
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

        } catch (SQLException e) {
            LOGGER.debug("Unable to find all cartItem for given cart id");
        }
    }

    private static final String FIND_BY_ID = "SELECT id, " +
            " total_price, " +
            " total_item, " +
            " version, " +
            " date_created, " +
            " date_last_updated, " +
            " user_id FROM cart WHERE id = ? ";
    @Override
    public Cart findOne(long cartId) {
        try (var c = ds.getConnection();
             var ps = c.prepareStatement(FIND_BY_ID))
        {
            ps.setLong(1, cartId);

            var res = ps.executeQuery();
            return extractCarts(res).get(0);
        } catch (SQLException e) {
            LOGGER.debug("Unable to find all cartItem for given cart id");
            return null;
        }
    }

    private Cart extractCart(ResultSet resultSet)
            throws SQLException {
        var cart = new Cart();
        cart.setId(resultSet.getLong("id"));
        cart.setTotalPrice(resultSet.getBigDecimal("total_price"));
        cart.setTotalItem(resultSet.getInt("total_item"));
        cart.setVersion(resultSet.getLong("version"));
        cart.setDateCreated(
                resultSet.getTimestamp("date_created")
                        .toLocalDateTime());
        cart.setDateLastUpdated(
                resultSet.getTimestamp("date_last_updated")
                        .toLocalDateTime());

        return cart;
    }

    private static final String FIND_ALL_CART_ITEMS = "select *" +
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
            return new HashSet<>();
        }
    }

    private List<Cart> extractCarts(ResultSet res) throws SQLException {
        List<Cart> carts = new ArrayList<>();
        while (res.next()) {
            var cart = new Cart();
            cart.setId(res.getLong("id"));
            cart.setTotalPrice(res.getBigDecimal("total_price"));
            cart.setTotalItem(res.getInt("total_item"));
            cart.setVersion(res.getLong("version"));
            cart.setDateLastUpdated(res.getTimestamp("date_last_updated").toLocalDateTime());
            cart.setDateCreated(res.getTimestamp("date_created").toLocalDateTime());
            carts.add(cart);
        }
        return carts;
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
}
