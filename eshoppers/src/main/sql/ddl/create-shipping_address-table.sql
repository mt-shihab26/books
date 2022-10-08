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