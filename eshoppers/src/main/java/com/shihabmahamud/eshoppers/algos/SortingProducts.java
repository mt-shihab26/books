package com.shihabmahamud.eshoppers.algos;

import com.shihabmahamud.eshoppers.dto.ProductDTO;

import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class SortingProducts {
    private static boolean compare(String a, String b) {
        int len = Math.min(a.length(), b.length());
        for (int i = 0; i < len; i++) {
            char ca = a.charAt(i);
            char cb = b.charAt(i);
            if (ca < cb) return true;
            else if (ca > cb) return false;
        }
        return a.length() < b.length();
    }
    private static void mergeSort(ProductDTO[] products, int start, int end) {
       if (start == end)
           return;
       var mid = start + (end - start) / 2;

       mergeSort(products, start, mid);
       mergeSort(products, mid+1, end);

       var len = end - start + 1;
       var merged = new ProductDTO[len];

       var first_half = start;
       var second_half = mid+1;

       for (var i = 0; i < len; i++) {
           if (first_half > mid)
               merged[i] = products[second_half++];
           else if (second_half > end)
               merged[i] = products[first_half++];
           else if (compare(products[first_half].getName(), products[second_half].getName()))
                merged[i] = products[first_half++];
           else
                merged[i] = products[second_half++];
       }

       for (int i = 0, j = start; i < len; i++, j++) {
           products[j] = merged[i];
       }
    }
    public static List<ProductDTO> byName(List<ProductDTO> products, Boolean isAsc) {
        var productArr = products.toArray(new ProductDTO[0]);
        mergeSort(productArr, 0, products.size()-1);

        var sortedProducts = Arrays.asList(productArr);
        if (!isAsc) Collections.reverse(sortedProducts);
        return sortedProducts;
    }

    public static List<ProductDTO> byPrice(List<ProductDTO> products, Boolean isAsc) {
        var sortedProducts = products
                .stream()
                .sorted(Comparator.comparing(ProductDTO::getPrice))
                .collect(Collectors.toList());
        if (!isAsc) Collections.reverse(sortedProducts);
        return sortedProducts;
    }

    public static List<ProductDTO> byDescription(List<ProductDTO> products, Boolean isAsc) {
        var sortedProducts = products
                .stream()
                .sorted(Comparator.comparing(ProductDTO::getDescription))
                .collect(Collectors.toList());
        if (!isAsc) Collections.reverse(sortedProducts);
        return sortedProducts;
    }
}
