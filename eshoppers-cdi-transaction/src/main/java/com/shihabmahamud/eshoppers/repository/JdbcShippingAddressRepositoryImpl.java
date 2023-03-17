package com.shihabmahamud.eshoppers.repository;

import com.shihabmahamud.eshoppers.domain.ShippingAddress;
import com.shihabmahamud.eshoppers.jdbc.JDBCTemplate;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import javax.inject.Inject;
import java.time.LocalDateTime;

public class JdbcShippingAddressRepositoryImpl implements ShippingAddressRepository {
    private static final Logger LOGGER = LoggerFactory.getLogger(JdbcShippingAddressRepositoryImpl.class);

    @Inject
    private JDBCTemplate jt;

    @Override
    public ShippingAddress save(ShippingAddress sd) {
        LOGGER.debug("Creating new shopping address");

        sd.setVersion(0L);
        sd.setDateCreated(LocalDateTime.now());
        sd.setDateLastUpdated(LocalDateTime.now());

        var id = jt.executeInsertQuery("""
                INSERT INTO shipping_address (
                    address,
                    address2,
                    state,
                    zip,
                    country,
                    version,
                    mobile_number,
                    date_created,
                    date_last_updated
                )
                VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)
                """,
                sd.getAddress(),
                sd.getAddress2(),
                sd.getState(),
                sd.getZip(),
                sd.getCountry(),
                sd.getVersion(),
                sd.getMobileNumber(),
                sd.getDateCreated(),
                sd.getDateLastUpdated()
        );
        sd.setId(id);
        return sd;
    }

    @Override
    public ShippingAddress findOne(Long shippingAddressId) {
        LOGGER.debug("Find a shipping address by id : {}", shippingAddressId);

        var shippingAddresses = jt.queryForObject(
                "SELECT * FROM shipping_address WHERE id = ?",
                shippingAddressId,
                res -> {
                    var sd = new ShippingAddress();
                    sd.setId(res.getLong("id"));
                    sd.setAddress(res.getString("address"));
                    sd.setAddress2(res.getString("address2"));
                    sd.setState(res.getString("state"));
                    sd.setZip(res.getString("zip"));
                    sd.setCountry(res.getString("country"));
                    sd.setVersion(res.getLong("version"));
                    sd.setMobileNumber(res.getString("mobile_number"));
                    sd.setDateCreated(res.getTimestamp("date_created").toLocalDateTime());
                    sd.setDateLastUpdated(res.getTimestamp("date_last_updated").toLocalDateTime());
                    return sd;
                }
        );
        if (shippingAddresses.isEmpty())
            return null;
        return shippingAddresses.get(0);
    }
}
