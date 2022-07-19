#include <stdio.h>

int main(void)
{
    char ch;

    ch = getchar(), putchar(ch + 1);
    printf("\n");

    return 0;
}