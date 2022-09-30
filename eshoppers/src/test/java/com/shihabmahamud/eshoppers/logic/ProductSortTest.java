package com.shihabmahamud.eshoppers.logic;

import com.shihabmahamud.eshoppers.dto.ProductDTO;
import org.junit.Assert;
import org.junit.Test;

import java.math.BigDecimal;
import java.util.List;

public class ProductSortTest {
    private static final ProductDTO APPLE_I_PED = new ProductDTO(
            "Apple iPad",
            "Apple iPad 10.2 32GB",
            BigDecimal.valueOf(369.99)
    );

    public static final ProductDTO HEADPHONE = new ProductDTO(
            "Headphones",
            "Jabra Elite Bluetooth Headphones",
            BigDecimal.valueOf(249.99)
    );

    @Test
    public void testByName() {
        var sorted = ProductSort.byName(
                List.of(HEADPHONE, APPLE_I_PED));
        Assert.assertEquals(APPLE_I_PED.getName(), sorted.get(0).getName());
        Assert.assertEquals(HEADPHONE.getName(), sorted.get(1).getName());
    }
}
