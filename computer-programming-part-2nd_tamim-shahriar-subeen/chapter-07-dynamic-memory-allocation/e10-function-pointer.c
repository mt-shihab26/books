#include <stdio.h>

int add(int n1, int n2)
{
    return n1 + n2;
}

int sub (int n1, int n2)
{
    return n1 - n2;
}

int main(void)
{
    int (*fnc)(int, int); // function type pointer variable declearation

    int n1 = 10, n2 = 5;

    fnc = &add;

    printf("Result : %d\n", fnc(n1, n2));

    fnc = &sub;

    printf("Result : %d\n", fnc(n1, n2));

    return 0;
}