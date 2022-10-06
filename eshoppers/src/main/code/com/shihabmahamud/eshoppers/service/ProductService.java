package com.shihabmahamud.eshoppers.service;

import com.shihabmahamud.eshoppers.dto.ProductDTO;

import java.util.List;

public interface ProductService {
    List<ProductDTO> findAllProductSortedByName();
}

