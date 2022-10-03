package com.shihabmahamud.eshoppers.util;

import javax.validation.ConstraintValidator;
import javax.validation.ConstraintValidatorContext;
import java.lang.reflect.Field;
import java.util.Objects;

public class PasswordEqualValidator implements ConstraintValidator<PasswordEqual, Object> {
    private String firstFiledName;
    private String secondFiledName;
    private String message;

    @Override
    public void initialize(PasswordEqual constraint) {
        firstFiledName = constraint.first();
        secondFiledName = constraint.second();
        message = constraint.message();
    }

    @Override
    public boolean isValid(Object value, ConstraintValidatorContext context) {
        boolean valid = true;

        try {
            final Object firstObj = getValue(value, firstFiledName);
            final Object secondObj = getValue(value, secondFiledName);

            valid = Objects.equals(firstObj, secondObj);
        } catch (final Exception ignore){
            // ignore
        }

        if (!valid) {
            context.buildConstraintViolationWithTemplate(message)
                    .addPropertyNode(firstFiledName)
                    .addConstraintViolation()
                    .disableDefaultConstraintViolation();
        }

        return valid;
    }

    private Object getValue(Object object, String fieldName) throws NoSuchFieldException, IllegalAccessException {
        Field field = object.getClass().getDeclaredField(fieldName);
        field.setAccessible(true);
        return field.get(object);
    }
}
