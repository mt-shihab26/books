package com.shihabmahamud.eshoppers.service;

import com.shihabmahamud.eshoppers.domain.Product;
import com.shihabmahamud.eshoppers.repository.ProductRepository;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;
import org.mockito.Mock;

import java.math.BigDecimal;
import java.util.List;

import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.when;

public class ProductServiceImplTest {

    private static final Product APPLE_I_PAD = new Product(
            1L,
            "Apple iPad",
            "Apple iPad 10.2 32GB",
            BigDecimal.valueOf(369.99), 4.2);
    private static final Product HEADPHONE
            = new Product(
            2L,
            "Headphones",
            "Jabra Elite Bluetooth Headphones",
            BigDecimal.valueOf(249.99), 4.5);

    @Mock
    private ProductRepository productRepository;

    private ProductService productService;

    @Before
    public void setUp() throws Exception {
        productRepository = mock(ProductRepository.class);
        productService = new ProductServiceImpl(productRepository);
    }

    @Test
    public void testFindAllProductSortedByName() {

        when(productRepository.findAllProduct())
                .thenReturn(List.of(
                                HEADPHONE,
                                APPLE_I_PAD)
                );

        var sortedByName = productService.findAllProductSortedByName();

        Assert.assertEquals(APPLE_I_PAD.getName(), sortedByName.get(0).getName());
        Assert.assertEquals(HEADPHONE.getName(), sortedByName.get(1).getName());
    }

    @Test
    public void testFindAllProductSortedByName2() {

        when(productRepository.findAllProduct())
                .thenReturn(List.of(
                        HEADPHONE,
                        APPLE_I_PAD)
                );

        var sortedByName = productService.findAllProductSortedByName();

        Assert.assertEquals(APPLE_I_PAD.getName(), sortedByName.get(0).getName());
        Assert.assertEquals(HEADPHONE.getName(), sortedByName.get(1).getName());
    }
}