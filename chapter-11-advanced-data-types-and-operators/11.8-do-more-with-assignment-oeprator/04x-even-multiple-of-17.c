#include <stdio.h>

int main(void)
{
    for (int i = 0; i <= 1000; i += 17)
        if (i % 2 == 0)
            printf("%d ", i);

    printf("\n");

    return 0;
}