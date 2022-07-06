# Chapter 11 - Advanced Data Types and Operators

## 11.1 - Use the storage class specifiers

- C defines four type modifiers that affect how a variable is stored.
  - `auto`
  - `extern`
  - `register`
  - `static`
- `auto` use for making Automatic variable. Automatic variables are simply local variable, which are auto by default.
- The `static` modifier may also be used on global variables. When it is, it causes the global variable to be known to and accessible by only the functions in the same file in which it is declared. Not only is a function not declared in the same file in which it is declared.
- Storage classes table
  | Storage Class | Keyword | Default | Storage | Scope | Life |
  | ------------- | ---------- | -------- | -------- | -------------------------------------------- | ------------------------------------------------------- |
  | Automatic | `auto` | Garbage | RAM | Limited to the block in which it is declared | Till the execution of the block in which it is declared |
  | Register | `register` | Garbage | register | Limited to the block in which it is declared | Till the execution of the block in which it is declared |
  | Static | `static` | 0 (zero) | RAM | Limited to the block in which it is declared | Till the End of program |
  | External | `extern` | 0 (zero) | RAM | Global | Till the End of program |

## 11.2 - Use the access modifiers

- C includes two type modifiers that affect the way variables ar accessed by both your program and the compiler.
  - `const`
  - `volatile`
- The qualifier const can be applied to the declaration of any variable to specify that its value will not be changed.
- C's **volatile keyword** is a qualifier that is applied to a variable when it is declared. It tells the compiler that the value of the **variable may change** at any time without any action being taken by the code. So it can't optimize is such a way tha repeated references to the value of the variable don't access the actual variable's storage for each reference. **Always Read From Memory** - No Optimization Possible.

## 11.3 - Define Enumerations

- `enum color_type { red, green, yellow }`;
- `enum color_type { red, green = 9, yellow }`;
- Two of the main uses of an enumeration are to help provide self-documenting code and to clarify the structure of your program

## 11.4 - Understand typedef

- Keep two points firmly in mind: First, a typedef does not cause the original name to be deactivated. second, you can use several typedef statements to create many different.

## 11.5 - Use C's Bitwise operators

- & : bitwise AND
- | : bitwise OR
- ^ : bitwise XOR ( exclusive OR)
- ~ : 1's complement (unary operator)
- Work with `character` and `integer` types. They can't used in `floating point` types
- high-order bit