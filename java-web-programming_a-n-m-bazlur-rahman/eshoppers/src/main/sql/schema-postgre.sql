CREATE TABLE "user"
(
    id SERIAL PRIMARY KEY,
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
    id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    description VARCHAR(500) NULL,
    price DECIMAL NOT NULL,
    rating DECIMAL NULL,
    version BIGINT NOT NULL,
    date_created TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    date_last_updated TIMESTAMP DEFAULT CURRENT_TIMESTAMP
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


