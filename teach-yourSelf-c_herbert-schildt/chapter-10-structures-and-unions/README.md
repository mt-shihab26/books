# Chapter 10 - Structures and Unions

## English words

## The Standard Header files

- **stdin**, **stdout** and **sterr** are three streams that are opened automaticaly when your C program begins executing. By Default they refer to the console, but in operating systems that support I/O redirection, they can be redirected to other devices.
- The **printf()** and **scanf()** functions are part of the C file system. They are simply special case functions that automatically use stdin and stdout.

## 10.1 - Master Structure Basics

- Each structure is a valid C type
- why use **sizeof** operator
  - Ensures that our code is portable in different environmetst
  - In some situations, the compilar may need to aliagn certain types of data on even word boundaries. In this case, the size of the structure will be larger than the sum of ints individual elements.
  - For computers based on the 8086 family of CPUs (such as the 80486 or the Pentium), there are several different ways the compiler can organize memory.
- The name of structure members will not confilict with other variables using the same names. Because the number name is linked with the structure name. is is separate from other variable of the same name.

## 10.2 - Declare Pointers to Structures

- Arrow operator `->`
- When accessing a member using a structure variable, use dot operator
- When accessing a member using a pointer, use the arrow operator
- <time.h> header file
- in <time.h> `tm` structure can hold the date and time `broken down` into its elements.
- `time()` function
- `localtime()` function
- `gmtime()` function

## 10.3 - Work with Nested Structures

## 10.4 - Understand Bit-fileds

- Bit fields are use to consume memory effciently when we know that the value of a filed or group of fields will never exceed a limit or is within a small range
- It can be used in structure and union
- We can optimize the space using bit fields

## 10.5 - Create Unions

- union can be use encode or decode int date
