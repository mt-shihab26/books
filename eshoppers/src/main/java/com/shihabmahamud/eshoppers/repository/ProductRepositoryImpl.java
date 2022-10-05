package com.shihabmahamud.eshoppers.repository;

import com.shihabmahamud.eshoppers.domain.Product;

import java.math.BigDecimal;
import java.util.List;

public class ProductRepositoryImpl implements ProductRepository{
    private static final List<Product> ALL_PRODUCTS = List.of(
            new Product(
                    1L,
                    "Apple iPad",
                    "Apple iPad 10.2 32GB",
                    BigDecimal.valueOf(369.99),
                    4.9
            ),
            new Product(
                    2L,
                    "Headphones",
                    "Jabra Elite Bluetooth Headphones",
                    BigDecimal.valueOf(249.99),
                    4.2
            ),
            new Product(
                    3L,
                    "Microsoft Surface Pro",
                    "Microsoft Surface Pro 7 12.3\" 120GB Windows 10" +
                            "Tablet with 10th Gen Intel Core i3/4GB RAM - " +
                            "Platinum",
                    BigDecimal.valueOf(799.99),
                    4.5
            ),
            new Product(
                    4L,
                    "Amazon Echo Dot",
                    "Amazon Echo Dot (3rd Gen) with Alexa - Charcoal",
                    BigDecimal.valueOf(34.99),
                    4.9
            )
    );

    @Override
    public List<Product> findAllProduct() {
        return ALL_PRODUCTS;
    }

    @Override
    public Product findById(Long productId) {
        return findAllProduct()
                .stream()
                .filter(product -> product.getId().equals(productId))
                .findFirst()
                .orElse(null);
    }
}
