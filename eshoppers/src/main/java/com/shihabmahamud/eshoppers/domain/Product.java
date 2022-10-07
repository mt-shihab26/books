package com.shihabmahamud.eshoppers.domain;

import java.math.BigDecimal;
import java.time.LocalDateTime;
import java.util.Objects;

public class Product extends Domain {
    private String name;
    private String description;
    private BigDecimal price;
    private Double rating;
    public Product (
            Long id ,
            String name,
            String description,
            BigDecimal price,
            Double rating
    )
    {
        super.setId(id);
        this.name = name;
        this.description = description;
        this.price = price;
        this.rating = rating;
    }

    public Product(
            Long id ,
            String name,
            String description,
            BigDecimal price,
            Double rating,
            Long version,
            LocalDateTime date_created,
            LocalDateTime date_last_updated
    )
    {
        super.setId(id);
        super.setDateCreated(date_created);
        super.setDateLastUpdated(date_last_updated);
        super.setVersion(version);
        this.name = name;
        this.description = description;
        this.price = price;
        this.rating = rating;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Product product)) return false;
        return Objects.equals(getId(), product.getId());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getId());
    }

    public Double getRating() {
        return rating;
    }

    public void setRating(Double rating) {
        this.rating = rating;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public BigDecimal getPrice() {
        return price;
    }

    public void setPrice(BigDecimal price) {
        this.price = price;
    }
}
