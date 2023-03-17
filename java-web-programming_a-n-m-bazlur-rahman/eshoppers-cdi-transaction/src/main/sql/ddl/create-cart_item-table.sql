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
