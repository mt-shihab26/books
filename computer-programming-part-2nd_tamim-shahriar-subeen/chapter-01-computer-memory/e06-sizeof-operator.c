#include <stdio.h>

int main(void)
{
    int num;
    char ch;
    double d_num;
    float f_num;

    printf("%lu\n", sizeof(int));
    printf("Size of int: %ld\n", sizeof(num));
    printf("Size of char: %ld\n", sizeof(ch));
    printf("Size of double: %ld\n", sizeof(d_num));
    printf("Size of float: %ld\n", sizeof(f_num));

    return 0;
}