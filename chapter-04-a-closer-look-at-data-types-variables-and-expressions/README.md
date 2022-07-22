# Chapter 04 - A Closer Look at Data Types, Variables and Expressions

## English Words:-

1. precisely = অবিকল
2. precise = সুনির্দিষ্ট
3. forth = সামনে
4. exact = হুবহু
5. retain = ধরে রাখা
6. piece = টুকরা
7. prior = পূর্বে

## key:-

### 4.1 - Use C's Data-Type Modifiers

1. C has five basic data types: `void`, `char`, `int`, `float`, `double`
2. The type modifiers are `long`, `short`, `signed`, `unsigned`
3. All data types defined the ANSI C Standard
   | Type | Typical Size in Bits | Minimal Range | Formate specifiers |
   | -------------------- | -------------------- | ------------- | ------------------ |
   | `char` | 8 bit | | |
   | `unsigned char` | 8 bit | | |
   | `signed char` | 8 ibit | | |
   | `int` | 32bit | | |
   | `unsigned int` | 32bit | | |
   | `signed int` | 32bit | | |
   | `short int` | 16bit | | |
   | `unsigned short int` | 16bit | | |
   | `signed short int` | 16bit | | |
   | `long int` | 64bit | | |
   | `signed long int` | 64bit | | |
   | `unsigned long int` | 64bit | | |
   | `float` | 32bit | | |
   | `double` | 64bit | | |
   | `long double` | 128bit | | |

### 4.2 - Learn where variables are declared

1. **Local variables** (declared inside a function)
2. Keyword `auto`
3. **Global variables**
4. When local and global variables share the same name, the compiler will always use the local variable.

### 4.3 - Take a closer look at Constants

### 4.4 - Initialize Variables

1. A variable may be giben an initial value when it is declared. This is called **variable initialization**
2. Global variables that are not explicitly initialized are automatically set to **zero**.
3. Local variables that are not initialized should be assumed to contain unknown values.

### 4.5 - Understand Type conversions in expressions

1. **`integral promotion`**
2. **`type promotion`**
3. in type promotion the C compiler will convert all operands "up" to the type of the largest operand.

### 4.6 - Understand type conversion in assignments

### 4.7 - Program with type casts

1. **type cast** takes this general from: `(type) value`
2. You cannot cast a variable that is on the left side of an assignment statement.
