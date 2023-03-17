#include <stdio.h>

int main(void)
{
    int x = 10, y;
    int *p, *q;

    p = &x;
    q = &y;
    y = *p;
    *p = 15;
    *q = 20;

    printf("Value of x: %d\n", x); // 15
    printf("Value of y: %d\n", y); // 20
    printf("Value of *p: %d\n", *p); // 15
    printf("Value of *q: %d\n", *q); // 20
}