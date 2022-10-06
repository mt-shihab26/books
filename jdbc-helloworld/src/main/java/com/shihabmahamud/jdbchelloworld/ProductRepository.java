package com.shihabmahamud.jdbchelloworld;

import java.sql.SQLException;
import java.util.List;

public interface ProductRepository {
    void save(Product product);
    List<Product> findAll();
}
