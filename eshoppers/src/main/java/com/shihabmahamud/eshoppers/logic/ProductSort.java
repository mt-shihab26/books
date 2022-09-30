package com.shihabmahamud.eshoppers.logic;

import com.shihabmahamud.eshoppers.dto.ProductDTO;

import java.util.Arrays;
import java.util.List;

public class ProductSort {
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
       int mid = start + (end - start) / 2;

       mergeSort(products, start, mid);
       mergeSort(products, mid+1, end);

       int len = end - start + 1;
       ProductDTO[] merged = new ProductDTO[len];

       int first_half = start, second_half = mid+1;

       for (int i = 0; i < len; i++) {
           if (first_half > mid) {
               merged[i] = products[second_half++];
           }
           else if (second_half > end) {
               merged[i] = products[first_half++];
           }
           else if (compare(products[first_half].getName(), products[second_half].getName())) {
                merged[i] = products[first_half++];
           }
           else {
                merged[i] = products[second_half++];
           }
       }

       for (int i = 0, j = start; i < len; i++, j++) {
           products[j] = merged[i];
       }
    }
    public static List<ProductDTO> byName(List<ProductDTO> products) {
        ProductDTO[] productArr = products.toArray(new ProductDTO[0]);
        mergeSort(productArr, 0, products.size()-1);
        return Arrays.asList(productArr);
    }
}
