#include <stdio.h>

int main(void)
{
    union t_type {
        long l;
        int i;
    } uvar;

    uvar.l = 0L; // clear 1;
    uvar.i = 100;

    printf("%d", uvar.i);

    return 0;
}