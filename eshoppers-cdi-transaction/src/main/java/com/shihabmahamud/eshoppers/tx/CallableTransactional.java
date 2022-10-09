package com.shihabmahamud.eshoppers.tx;

@FunctionalInterface
public interface CallableTransactional<T> {
    T doInTransaction();
}
