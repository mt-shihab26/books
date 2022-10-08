CREATE TABLE `order`
(
    id                      BIGINT      AUTO_INCREMENT PRIMARY KEY,
    version                 BIGINT      NOT NULL,
    shipping_date           TIMESTAMP   NULL,
    date_created            TIMESTAMP   NOT NULL,
    date_last_updated       TIMESTAMP   NOT NULL,
    user_id                 BIGINT      NOT NULL,
    cart_id                 BIGINT      NOT NULL,
    shipping_address_id     BIGINT      NOT NULL,

    CONSTRAINT order_shipping_address_id_fk
    FOREIGN KEY (shipping_address_id)
    REFERENCES shipping_address (id),

    CONSTRAINT order_cart_id_fk
    FOREIGN KEY (cart_id)
    REFERENCES cart (id),

    CONSTRAINT order_user_id_fk
    FOREIGN KEY (user_id)
    REFERENCES user (id)
);
