#include <stdio.h>

int main(void)
{
    register int i, sum;

    sum = 0;

    for (i = 1; i < 101; i++)
        sum += i;

    printf("%d\n", sum);
    return 0;
}