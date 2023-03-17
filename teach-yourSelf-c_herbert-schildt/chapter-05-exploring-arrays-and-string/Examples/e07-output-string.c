#include <stdio.h>

int main(void)
{
    char str[80];

    printf("Enter a string (less than 80 chars): ");
    gets(str);
    printf(str); // output the string

    return 0;
}