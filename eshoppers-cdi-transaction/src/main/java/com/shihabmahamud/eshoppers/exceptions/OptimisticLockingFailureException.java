package com.shihabmahamud.eshoppers.exceptions;

public class OptimisticLockingFailureException extends RuntimeException {
    public OptimisticLockingFailureException(String s) {
        super(s);
    }
}
