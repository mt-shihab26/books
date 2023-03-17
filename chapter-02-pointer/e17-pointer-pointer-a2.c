#include <stdio.h>

int main(void)
{
    char c = 'A';
    char *p, **q;

    p = &c;
    q = &p;

    **q = 'B';

    printf("Value of c: %c\n", c);
    printf("Value of c: %c\n", *p);
    printf("Value of c: %c\n", **q);
}