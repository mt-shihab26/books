package com.shihabmahamud.eshoppers.repository;

import com.shihabmahamud.eshoppers.dto.ProductDTO;

import java.util.List;

public interface ProductRepository {
    List<ProductDTO> findAllProduct();
}
