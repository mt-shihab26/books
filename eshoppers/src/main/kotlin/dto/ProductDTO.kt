package dto

import java.math.BigDecimal

class ProductDTO(
        var name: String,
        var description: String,
        var price: BigDecimal,
        var rating: Double
)