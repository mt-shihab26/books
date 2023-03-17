CREATE TABLE user
(
    id BIGINT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(32) NOT NULL,
    password VARCHAR(200) NOT NULL,
    email VARCHAR(64) NULL,
    first_name varchar(32) NOT NULL,
    last_name varchar(32) NOT NULL,
    version BIGINT NOT NULL,
    date_created TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    date_last_updated TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE product (
    id BIGINT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    description VARCHAR(500) NULL,
    price DECIMAL NOT NULL,
    rating DECIMAL NULL,
    version BIGINT NOT NULL,
    date_created TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    date_last_updated TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE cart (
    id BIGINT AUTO_INCREMENT PRIMARY KEY,
    total_price DECIMAL NULL,
    total_item INT NULL,
    version BIGINT NOT NULL,
    date_last_updated TIMESTAMP NOT NULL,
    date_created TIMESTAMP NOT NULL,
    user_id BIGINT NOT NULL,
    CONSTRAINT cart_user_id_fk FOREIGN KEY (user_id) REFERENCES user (id)
);

CREATE TABLE cart_item (
    id BIGINT AUTO_INCREMENT PRIMARY KEY,
    quantity INT NOT NULL,
    price DECIMAL NULL,
    version BIGINT NOT NULL,
    date_last_updated TIMESTAMP NOT NULL,
    date_created TIMESTAMP NOT NULL,
    product_id BIGINT NOT NULL,
    cart_id BIGINT NOT NULL,

    CONSTRAINT cart_item_product_id_fk FOREIGN KEY (product_id) REFERENCES product (id),
    CONSTRAINT cart_item_cart_id_fk FOREIGN KEY (cart_id) REFERENCES cart (id)
);

CREATE TABLE shipping_address
(
    id                  BIGINT          AUTO_INCREMENT PRIMARY KEY,
    address             VARCHAR(250)    NOT NULL,
    address2            VARCHAR(250)    NOT NULL,
    state               VARCHAR(20)     NULL,
    zip                 VARCHAR(10)     NULL,
    country             VARCHAR(30)     NULL,
    version             BIGINT          NOT NULL,
    date_created        TIMESTAMP       NOT NULL,
    date_last_updated   TIMESTAMP       NOT NULL,
    mobile_number       VARCHAR(20)     NULL
);

CREATE TABLE `order`
(
    id                      BIGINT      AUTO_INCREMENT PRIMARY KEY,
    version                 BIGINT      NOT NULL,
    shipping_date           TIMESTAMP   NULL,
    shipped                 TINYINT(1)  NULL,
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


INSERT INTO product (
    name,
    description,
    price,
    rating,
    version
)
VALUES (
    'Apple iPad',
    'Apple iPad 10.2 32GB',
    369.99,
    4.9,
    1
);

INSERT INTO product (
    name,
    description,
    price,
    rating,
    version
)
VALUES (
    'Headphones',
    'Jabra Elite Bluetooth Headphones',
    249.99,
    4.2,
    0
);

INSERT INTO product (
    name,
    description,
    price,
    rating,
    version
)
VALUES (
    'Microsoft Surface Pro',
    'Microsoft Surface Pro 7 12.3\" 120GB Windows 10" +
                                 "Tablet with 10th Gen Intel Core i3/4GB RAM - " +
                                 "Platinum',
    799.99,
    4.5,
    0
);
