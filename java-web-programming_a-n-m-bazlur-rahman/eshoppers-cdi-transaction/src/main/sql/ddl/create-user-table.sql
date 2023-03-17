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
)