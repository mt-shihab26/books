#include <stdio.h>

int main(void)
{
    int i, j;

    for (i = 0, j = 100; i <= j; i++, j--)
        printf("%d ", i);

    printf("\n");

    return 0;
}