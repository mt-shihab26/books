package com.shihabmahamud.eshoppers.dto;

import java.math.BigDecimal;

public class ProductDTO {
    private String name, description;
    private BigDecimal price;
    private Double rating;

    public ProductDTO(String name, String description,
                      BigDecimal price, Double rating) {
        this.name = name;
        this.description = description;
        this.price = price;
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

    public Double getRating() {
        return rating;
    }

    public void setRating(Double rating) {
        this.rating = rating;
    }
}
