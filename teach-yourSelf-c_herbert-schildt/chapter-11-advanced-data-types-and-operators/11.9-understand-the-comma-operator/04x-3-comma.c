#include <stdio.h>

int main(void)
{
    for (int i = 0, j = -50, z = i + j; i < 100; i++, j++, z = i + j)
        printf("%d ", z);
    printf("\n");

    return 0;
}