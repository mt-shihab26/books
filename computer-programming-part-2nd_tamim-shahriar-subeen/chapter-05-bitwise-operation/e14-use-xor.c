#include <stdio.h>

int main(void)
{
    int ara[] = {1, 2, 3, 4, 1, 2, 3};
    int result, i, n = 7;

    result = ara[0];
    for (i = 0; i < n; i++)
        result = result ^ ara[i];

    printf("Result: %d\n", result);
}