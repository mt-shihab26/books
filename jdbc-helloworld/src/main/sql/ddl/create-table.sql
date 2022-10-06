CREATE TABLE product (
    id BIGINT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    description VARCHAR(500) NULL,
    price DECIMAL NOT NULL,
    version BIGINT NOT NULL,
    date_created TIMESTAMP NOT NULL,
    date_last_updated TIMESTAMP NULL
);