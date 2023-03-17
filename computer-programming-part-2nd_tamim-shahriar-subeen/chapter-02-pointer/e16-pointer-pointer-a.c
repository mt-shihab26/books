#include <stdio.h>

int main(void)
{
    char c = 'A';
    char *p;    // printer of char variable type
    char **q;   // pointer of pointer variable type

    p = &c;
    q = &p;

    printf("Value of c: %c\n", c);
    printf("Value of c: %c\n", *p);
    printf("Value of c: %c\n", **q);

    printf("Address of c: %p\n", &c);
    printf("Value of p: %p\n", p);
    printf("Value of *q: %p\n", *q);

    printf("Address of p: %p\n", &p);
    printf("Value of q: %p\n", q);



    return 0;
}