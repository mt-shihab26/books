package algos

import com.shihabmahamud.eshoppers.algos.SortingProducts
import dto.ProductDTO
import org.junit.Assert
import org.junit.Test
import java.math.BigDecimal

class ProductSortTest {
    @Test
    fun testByName() {
        val sorted = SortingProducts.byName(
            listOf(HEADPHONE, APPLE_I_PED), true
        )
        Assert.assertEquals(APPLE_I_PED.name, sorted[0].name)
        Assert.assertEquals(HEADPHONE.name, sorted[1].name)
    }

    companion object {
        private val APPLE_I_PED = ProductDTO(
            "Apple iPad",
            "Apple iPad 10.2 32GB",
            BigDecimal.valueOf(369.99),
            4.9
        )
        val HEADPHONE = ProductDTO(
            "Headphones",
            "Jabra Elite Bluetooth Headphones",
            BigDecimal.valueOf(249.99),
            4.2
        )
    }
}