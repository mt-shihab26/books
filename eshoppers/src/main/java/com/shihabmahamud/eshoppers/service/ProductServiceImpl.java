package com.shihabmahamud.eshoppers.service;

import com.shihabmahamud.eshoppers.domain.Product;
import com.shihabmahamud.eshoppers.util.SortingProducts;
import com.shihabmahamud.eshoppers.dto.ProductDTO;
import com.shihabmahamud.eshoppers.repository.ProductRepository;

import java.util.ArrayList;
import java.util.List;

public class ProductServiceImpl implements ProductService{
    private final ProductRepository productRepository;

    public ProductServiceImpl(ProductRepository productRepository) {
       this.productRepository = productRepository;
    }

    @Override
    public List<ProductDTO> findAllProductSortedByName() {
        var products = SortingProducts
                .byName(productRepository.findAllProduct(), false);
        return convertToProductDTO(products);
    }

    private List<ProductDTO> convertToProductDTO(List<Product> products) {
        List<ProductDTO> productsDTO = new ArrayList<>();
        for (Product product : products) {
            productsDTO.add(new ProductDTO(
                    product.getId(),
                    product.getName(),
                    product.getDescription(),
                    product.getPrice(),
                    product.getRating()
                )
            );
        }
        return productsDTO;
    }
}
