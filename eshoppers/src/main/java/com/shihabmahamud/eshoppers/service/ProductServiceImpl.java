package com.shihabmahamud.eshoppers.service;

import com.shihabmahamud.eshoppers.algos.SortingProducts;
import dto.ProductDTO;
import com.shihabmahamud.eshoppers.repository.ProductRepository;

import java.util.List;

public class ProductServiceImpl implements ProductService{
    private final ProductRepository productRepository;

    public ProductServiceImpl(ProductRepository productRepository) {
       this.productRepository = productRepository;
    }

    @Override
    public List<ProductDTO> findAllProductSortedByName() {
        return SortingProducts.byRating(productRepository.findAllProduct(), false);
    }
}
