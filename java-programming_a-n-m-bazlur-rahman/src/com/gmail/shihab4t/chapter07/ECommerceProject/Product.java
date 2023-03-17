package com.gmail.shihab4t.chapter07.ECommerceProject;

public class Product {
    private final int SHIPPING_RATE = 5;
    private final double DIMENSION_CHARGE = 1.5;

    private final String name;
    private final int weight;
    private final Dimension dimension;
    private int price;
    private int discount;

    public Product(String name, int price, int discount, int weight, Dimension dimension) {
        this.name = name;
        this.price = price;
        this.discount = discount;
        this.weight = weight;
        this.dimension = dimension;
    }

    public int getPrice() {
        double price = this.price * ((100 - discount) / 100.0);
        price += weight * SHIPPING_RATE;

        if (dimension.getVolume() > 10) {
            price += dimension.getVolume() * DIMENSION_CHARGE;
        }
        return (int) price;
    }

    @Override
    public String toString() {
        return "Product{" +
                "name='" + name + '\'' +
                ", weight=" + weight +
                ", dimension=" + dimension +
                ", price=" + price +
                ", discount=" + discount +
                '}';
    }
}
