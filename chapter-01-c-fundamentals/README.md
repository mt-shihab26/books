# Chapter 01 - C Fundamentals

Note: In program name

- b -> Review Skills Check
- e -> Examples
- x -> Exercise
- y -> Mastery Skills Check
- z -> Cumulative Skill

## The C standard Library functions:-

### <stdio.h>

1. printf()
2. scanf()

### <math.h>

1. sqrt()

## English Words:-

1. subroutine
2. Degenerative = অপজাত সম্বন্ধীয়
3. throughout = জুড়ে
4. braces = ধনুর্বন্ধনী
5. traits = বৈশিষ্ট্য
6. suspicious = সন্দেহজনক
7. Frankly = অকপটে
8. trivial = নগণ্য
9. precision = নির্ভুলতা
10. complementary = পরিপূরক
11. coincidence = কাকতালীয়
12. liberally = উদারভাবে
13. solely = একমাত্র
14. seems = মনে হচ্ছে
15. encountered = সম্মুখীন

## key:-

### 1.1 - Understand The components of a C program

1. All c statement s end with `a semicolon`
2. `main()` function
3. function `return type`
4. function `parameters`
5. The C standard Library functions
6. `printf()` function
7. header file
8. `#include` Preprocessor directive

### 1.2 - Create and Compile a Program

1. source file
2. object file of executable file

### 1.3 - Declare Variables and assign Values

1. Variables
2. Variables types
3. Character Data Types
   | Character Data Types | Size | Format Specifier |
   | :------------------- | ---------------------------------- | ---------------- |
   | `char` | `1byte` or `8bit` or `-128 to 127` | `%c` |
   | `unsigned char` | `1byte` or `8bi` or `0 to 255` | `%c` |
4. Integer Data Types
   Note: All character data types also integer data types
   | Integer Data Types | Size | Format Specifier |
   | ------------------------------------------------- | ------------------------------------------------------------ | ------------------------------ |
   | `short int` or `short` | `2bytes` or `16bit` or `-32,768 to 32,767` | `%hd` |
   | `unsigned short int` or `unsigned short` | `2bytes` or `16bit` or `0 to 65,535` | `%hd` |
   | `int` | `4bytes` or `34bit` or `-2,147,483,648 to 2,147,483,647` | `%d`, `%i`, `%u` |
   | `unsigned int` | `4bytes` or `34bit` or `0 to 4,294,967,295` | `%d` ,`%i` , `%u` |
   | `long long int` or `long long` or `long` | `8 bytes` or `64bit` or `-9223372036854775808 to 9223372036854775807` | `%lld`, `%lli` or `%ld`, `%li` |
   | `unsigned long long int` or `long long` or `long` | `8 bytes` or `64bit` or `0 to 18446744073709551615` | `%llu` or `%lu` |
5. Floating-point Data Types
   | Floating-point Data Types | Size | Format Specifier |
   | ------------------------- | --------------------------------------------- | ---------------- |
   | `float` | `4bytes` or `34bit` and `6 decimal places` | `%f` |
   | `double` | `8 byte `or `64bit` and `15 decimal places` | `%lf` |
   | `long double` | `16 byte` or `128bit` and `19 decimal places` | `%Lf` |
6. Void Data Types
   The void type specifies that no value is available. It is used in three kinds of situations −
   | Sr.No. | Types & Description |
   | :----: | :----------------------------------------------------------: |
   | 1 | **Function returns as void**There are various functions in C which do not return any value or you can say they return void. A function with no return value has the return type as void. For example, **void exit (int status);** |
   | 2 | **Function arguments as void**There are various functions in C which do not accept any parameter. A function with no parameter can accept a void. For example, **int rand(void);** |
   | 3 | **Pointers to void**A pointer of type void \* represents the address of an object, but not its type. For example, a memory allocation function **void \*malloc( size_t size );** returns a pointer to void which can be casted to any data type. |
7. Global Variables
8. Local variables
9. Constant

### 1.4 - Input Numbers from the keyboard

1. `scanf()` function

### 1.5 - Perform calculations using arithmetic expressions

1. Arithmetic expressions
2. C defines these five arithmetic operators
   | Arithmetic Operator | Meaning |
   | ------------------- | -------------- |
   | `+` | addition |
   | `-` | subtraction |
   | `*` | Multiplication |
   | `/` | division |
   | `%` | modulus |
3. `-` unary operator

### 1.6 - Add comments to a Program

1. Multiline commants `/* commant */`
2. The single-line comment `(//)`

### 1.7 - Write your own functions

1. function prototypes

### 1.8 - Use functions to return values

1. `sqrt()` function
2. function defaults return types is `int`
3. return function with no value

### 1.9 - Use Function Arguments

1. argument
2. the formal parameter of the function

### 1.10 - Remember the C keywords

1. ANSI C standard has 32keywords
<table>
<tbody>
<tr>
<td>

- [ ] `auto`
- [x] `break`
- [x] `case`
- [x] `char`
- [ ] `const`
- [x] `continue`
- [x] `default`
- [x] `do`
- [x] `double`
- [x] `else`
- [ ] `enum`
- [ ] `extern`

</td>
<td>

- [x] `float`
- [x] `for`
- [x] `goto`
- [x] `if`
- [x] `int`
- [x] `long`
- [ ] `register`
- [x] `return`
- [x] `short`

</td>
<td>

- [x] `signed`
- [x] `sizeof`
- [ ] `static`
- [x] `struct`
- [x] `switch`
- [x] `typedef`
- [ ] `union`
- [x] `unsigned`
- [x] `void`
- [ ] `volatile`
- [x] `while`

</td>
</tr>
</tbody>
</table>
