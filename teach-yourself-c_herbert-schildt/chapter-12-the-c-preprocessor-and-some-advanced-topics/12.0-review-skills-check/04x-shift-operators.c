#include <stdio.h>

int main(void)
{
    int i;

    printf("Enter a number: ");
    scanf("%d", &i);

    printf("Doubled: %d\n", i << 1);
    printf("Halved: %d\n", i >> 1);

    return 0;
}