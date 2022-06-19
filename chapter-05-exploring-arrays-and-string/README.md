# Chapter 05 - Exploring Arrays and String

## The C standard Library functions:-

### <stdio.h>

1. gets()

### <string.h>

1. `strcpy(to, form); // copies the contents of from to to`
2. `strcat(to, from); // function concatenate two string`
3. `strcmp(s1, s2); // compares two strings.`
4. `strlen(str); // return the length, in characters of astring`

### <stdlib.h>

1. `atoi (str); // Convert a string to an integer. return integer`

## English Words:

1. bounds = সীমা

## key:-

### 5.1 - Declare one-dimensional arrays

1. An individual variable in the array is called an array element.
2. Array element indexing at zero.
3. C does not perform any bounds checking on array indexes.
4. In C, you may not assign on entire array to another.
5. If array **overrun** it across error

### 5.2 - Use Strings

1. Unlike most other computer languages, C has no built-in string data type. instead, a string in defined as `a null-terminated` character array.
2. in C `null is zero` (`null` = `0`)
3. by `gets()` The enter key (carriage teturn) is not stored. but replaced by a **null**.
4. string Formate specifiers is `%s`
5. The C standard library supplies many string-related functions. The four most importnt are `strcpy()`, `strcat()`, `strcmp()`, `strlen()`.
6. The `strcpy(to form)` function performs no bounds checking.
7. The `strcat(to, from)` function concatenate two string. it's performs no bounds checking.
8. `lexicographically`
9. The `stelen(str)` does not count the `null terminator.
10. zero-length string (`strcpy(str, "")`). Such a string is called a `null string`. it contains only one element `the null terminator`

### 5.3 - Create Multidimensional Arrays

1. A two-dimensional array is essentially an array of one-dimensional arrays and is most easily thought of in a row, column format.

### 5.4 - Initialize Arrays

### 5.5 - Build Arrays of Strings
