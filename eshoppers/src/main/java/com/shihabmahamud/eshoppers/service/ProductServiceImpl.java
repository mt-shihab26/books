package com.shihabmahamud.eshoppers.service;

import com.shihabmahamud.eshoppers.dto.ProductDTO;
import com.shihabmahamud.eshoppers.logic.ProductSort;
import com.shihabmahamud.eshoppers.repository.ProductRepository;

//import java.util.Comparator;
import java.util.List;
//import java.util.stream.Collectors;

public class ProductServiceImpl implements ProductService{
    private final ProductRepository productRepository;

    public ProductServiceImpl(ProductRepository productRepository) {
       this.productRepository = productRepository;
    }

    @Override
    public List<ProductDTO> findAllProductSortedByName() {
//         return productRepository.findAllProduct()
//                .stream()
//                .sorted(Comparator.comparing(ProductDTO::getName))
//                .collect(Collectors.toList());
        return ProductSort.byName(productRepository.findAllProduct());
    }
}
