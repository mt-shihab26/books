package com.shihabmahamud.eshoppers.tx;

@FunctionalInterface
public interface Transactional {
    void doInTransaction();
}
