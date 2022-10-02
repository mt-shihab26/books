package com.shihabmahamud.eshoppers.service;

import dto.ProductDTO;

import java.util.List;

public interface ProductService {
    List<ProductDTO> findAllProductSortedByName();
}

