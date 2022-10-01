package com.shihabmahamud.eshoppers.service;

import com.shihabmahamud.eshoppers.algos.SortingProducts;
import com.shihabmahamud.eshoppers.dto.ProductDTO;
import com.shihabmahamud.eshoppers.repository.ProductRepository;

import java.util.List;

public class ProductServiceImpl implements ProductService{
    private final ProductRepository productRepository;

    public ProductServiceImpl(ProductRepository productRepository) {
       this.productRepository = productRepository;
    }

    @Override
    public List<ProductDTO> findAllProductSortedByName() {
        return SortingProducts.byName(productRepository.findAllProduct(), true);
    }
}
