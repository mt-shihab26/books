#include <stdio.h>

int main(void)
{
    printf("%.5d\n", 10);
    printf("$%.2f\n", 99.9800);
    printf("%.10s\n", "Not all of this will be printed\n");

    return 0;
}