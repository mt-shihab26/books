package com.shihabmahamud.eshoppers.repository;

import com.shihabmahamud.eshoppers.domain.Product;

import java.util.List;
import java.util.Optional;

public interface ProductRepository {
    List<Product> findAllProduct();
    Optional<Product> findById(Long productId);
}
