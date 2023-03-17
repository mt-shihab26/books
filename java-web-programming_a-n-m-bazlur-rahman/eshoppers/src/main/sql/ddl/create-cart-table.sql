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
