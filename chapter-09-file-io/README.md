# Chapter 09 - File I/O

## English words

1. redundant
2. accomplish
3. abstraction
4. often
5. retained

## The Standard Header files

```c
<stdio.h>

FILE *fopen(char*fname, char *made); // 1.
FILE structure// 2.
NULL Macro// 3.
int fclose(FILE *fp); // 4.

// Working with character

int fgetc(FILE *fp); also known as getc(); // 5.
int fputc(int ch, FILE *fp); also known as putc(); // 6.
int putchar(int __c); // 7.
void exit (int __status); // 8.

// Working with binary file

int feof(FILE *fp); // 9.
int ferror(FILE *fp); // 10.
int remove(const char *filename); // 11.

// Working with string

int fputs(char *str, FILE *fp); // 12.
int fgets(char *str, int num, FILE *fp); // 13.
int fprintf(FILE *fp, char *control-string, ...); // 14.
int fscanf(FILE *fp, char *control-string, ...); // 15.

// read and write binary date
size_t fread(void *buffer, size_t size, size_t num, FILE *fp); // 16
size_t fwite(void *buffer, size_t size, size_t num, FILE *fp); // 17

// Understand random access
int fseek(FILE *fp, long offset, int origin); // 18
long int ftell (FILE *__stream) // 19

// learn various file-system function
int rename(char *oldname, char *newname); // 20 return: zero if successful and nonzero if and error occours
int remove(char *file_name); // 21 return: zero if successful and nonzero if and error occours
void rewind(FILE *fp); // 22
int fflush(FILE *fp); // 23 return: zero if successful and EOF if a failure occurs

```

## File mode

```txt
The Legal Values for Mode

Mode        Meaning
----        -------
"r"         Open a text file for reading.
"w"         Create a text file for writing.
"a"         Append to a text file.
"rb"        Open a binary file for reading.
"wb"        Create a binary file for writing.
"ab"        Append to a binary file.
"r+"        Open a text file for read/write.
"w+"        Create a text file for read/write.
"a+"        Append or create a text file for read/write.
"r+b"       Open a binary file for read/write. You may also use "rb+".
"w+b"       Create a binary file for read/write. You may also use "wb+".
"a+b"       Append or create a binary file for read/write. You may also use "ab+".
```

## 9.1 - Understand Streams

1. the Stream
2. open operation
3. close opeartion
4. Text files
5. Binary files

## 9.2 - Master File-System Basics

1. read argument as file

## 9.3. Understand feof() and ferror()

1. feof()
2. ferror()
3. remove()

## 9.4. Learn some higher-level text fuctions

1. working with text files, C provides four function1 fputs(), fgets()

## 9.5. Learn to read and write binary date

1. void pointer or generic pointer
2. sizeof oprator (exemple: sizeof(type) or sizeof var_name)

## 9.6. Understand Random access

1. SEEK_SET
2. SEEK_CUR
3. SEEK_END

## 9.7. Learn about various File-sysstem functions

1. rename()
2. remove()
3. rewind()
4. fflush()

## 9.8. Learn about the standard streams

1. stdin stream
2. stdout stream
3. stderr stream
