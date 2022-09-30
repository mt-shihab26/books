package com.shihabmahamud.eshoppers.repository;

import com.shihabmahamud.eshoppers.dto.ProductDTO;

import java.math.BigDecimal;
import java.util.List;

public class DummyProductRepositoryImpl implements ProductRepository{
    @Override
    public List<ProductDTO> findAllProduct() {
        return List.of(
                new ProductDTO(
                        "Apple iPad",
                        "Apple iPad 10.2 32GB",
                        BigDecimal.valueOf(369.99)
                ),
                new ProductDTO(
                        "Headphones",
                        "Jabra Elite Bluetooth Headphones",
                        BigDecimal.valueOf(249.99)
                )
        );
    }
}
