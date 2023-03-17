# C Library

- function grouped
    - String and character functions
    - Mathematics functions
    - Dynamic allocation functions
    - IO functions
    - Time and Date functions
    - Miscellaneous functions

## String and character functions

- ctype.h
    - `int isalnum(int ch);`
    - `int isalpha(int ch);`
    - `int iscntrl()`
    - `int isdigit(int ch);`
    - `int isgraph(int ch);`
    - `int islower(int ch);`
    - `int isprint(int ch);`
    - `int ispunct(int ch);`
    - `int isspace(int ch);`
    - `int isupper(int ch);`
    - `int isxdigit(int ch);`
    - `int tolower(int ch);`
- string.h
    - `char *strcat(char *str1, const char *str2);`
    - `char *strchr(const char *str, int ch);`
    - `int strcmp(const char *str1, const char *str2);`
    - `char *strcpy(char *str1, const char *str2);`
    - `size_t strlen(const char *str);`
    - `char *strtok(const char *str1, const char *str2);`
- stdio.h
    - `char *strstr(const char *str1, const char *str2);`

## The Mathematics Functions

- Trigonometric functions
- Hyperbolic functions
- Exponential and logarithmic functions
- Miscellaneous functions
- `HUGE_VAL` macro
- math.h
    - `double acos(double arg);`
    - `double asin(double arg);`
    - `double atan(double arg);`
    - `double atan2(double y, double x);`
    - `double ceil(double num);`
    - `double cos(double arg);`
    - `double cosh(double arg);`
    - `double exp(double arg);`
    - `double fabs(double num);`
    - `double floor(double num);`
    - `double log(double num);`
    - `double log10(double num);`
    - `double pow(double base, double exp);`
    - `double sin(double arg);`
    - `double sinh(double arg);`
    - `double sinh(double num);`
    - `double tan(double num);`
    - `double tanh(double num);`

## Time and Date functions

- tm, time_t, clock_t, CLOCKS_PER_SEC
- time.h
    - `char *asctime(const struct tm *ptr);`
    - `clock_t clock(void)`
    - `char *ctime(const time_t *time);`
    - `double difftime(time_t time2, time_t time1);`
    - `struct tm *gmtime(const time_t *time);`
    - `struct tm *localtime(const time_t *time);`
    - `time_t time(time_t *systime);`

## Dynamic Allocation

- stdlib.h
    - `void calloc(size_t num, size_t size);`
    - `void free(void *ptr);`
    - `void malloc(size_t size);`
    - `void *realloc(void *ptr, size_t size);`

## Miscellaneous functions

- stdlib.h
    - `void abort(void);`
    - `int abs(int num);`
    - `double atof(const char *str);`
    - `int atoi(const char *str);`
    - `long atol(const char *str);`
    - `void *bsearch(const void *key, const void *base, size_t num, size_t size, int (*compare)(const void *, const void *);`
    - `void exit(int status);`
    - `long labs(long num)`;
    - `void longjmp(jmp_buf envbuf, int val);`
    - `void qsort(void *base, size_t num, size_t size, int(*compare)(const void *, const void*);`
    - `int rand(void);`
- setjmp.h
    - `int setjmp(jmp_buf envbuf);`
    - `void srand(unsigned seed);`
