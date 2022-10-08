package com.shihabmahamud.eshoppers.repository;

import com.shihabmahamud.eshoppers.domain.Cart;
import com.shihabmahamud.eshoppers.domain.Order;
import com.shihabmahamud.eshoppers.domain.ShippingAddress;
import com.shihabmahamud.eshoppers.domain.User;
import com.shihabmahamud.eshoppers.jdbc.JDBCTemplate;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.time.LocalDateTime;
import java.util.HashSet;
import java.util.Set;

public class JdbcOrderRepositoryImpl implements OrderRepository {
    private static final Logger LOGGER = LoggerFactory.getLogger(JdbcShippingAddressRepositoryImpl.class);
    private final CartRepository cartRepository = new JdbcCartRepositoryImpl();
    private final ShippingAddressRepository shippingAddressRepository = new JdbcShippingAddressRepositoryImpl();
    private final JDBCTemplate jt = new JDBCTemplate();

    @Override
    public Order save(Order order) {
        // order is a reserved word on mysql
        // so make sure you quote/back-tic before using it;
        LOGGER.debug("Creating new order in database");

        order.setVersion(0L);
        order.setDateCreated(LocalDateTime.now());
        order.setDateLastUpdated(LocalDateTime.now());

        var query = """
                INSERT INTO `order` (
                    shipping_address_id,
                    cart_id,
                    version,
                    shipped,
                    user_id,
                    date_created,
                    date_last_updated
                )
                VALUES (?, ?, ?, ?, ?, ?, ?)
                """;
        var id = jt.executeInsertQuery(
                query,
                order.getShippingAddress().getId(),
                order.getCart().getId(),
                order.getVersion(),
                order.getShipped(),
                order.getUser().getId(),
                order.getDateCreated(),
                order.getDateLastUpdated()
        );
        order.setId(id);

        return order;
    }

    @Override
    public Set<Order> findOrderByUser(User user) {
        var query = "SELECT * FORM `order` WHERE user_id = ?";
        var orders = jt.queryForObject(
                query,
                user.getId(),
                res -> {
                    var order = new Order();
                    order.setId(res.getLong("id"));
                    order.setVersion(res.getLong("version"));
                    order.setDateCreated(res.getTimestamp("date_created").toLocalDateTime());
                    order.setDateLastUpdated(res.getTimestamp("date_last_updated").toLocalDateTime());
                    order.setShipped(res.getBoolean("shipped"));
                    order.setShippingDate(res.getTimestamp("shipping_date") != null
                            ? res.getTimestamp("shipping_date").toLocalDateTime() : null);

                    Cart cart = cartRepository.findOne(res.getLong("cart_id"));
                    if (cart != null)
                        order.setCart(cart);

                    var shippingAddress = shippingAddressRepository
                            .findOne(res.getLong("shipping_address_id"));
                    if (shippingAddress != null)
                        order.setShippingAddress(shippingAddress);

                    order.setUser(user);

                    return order;
                }
        );
        return new HashSet<>(orders);
    }
}
