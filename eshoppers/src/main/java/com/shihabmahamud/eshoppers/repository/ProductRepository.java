package com.shihabmahamud.eshoppers.repository;

import dto.ProductDTO;

import java.util.List;

public interface ProductRepository {
    List<ProductDTO> findAllProduct();
}
