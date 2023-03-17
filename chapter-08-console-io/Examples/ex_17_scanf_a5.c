#include <stdio.h>

int main(void)
{
    int i, j;

    printf("Enter a decimal number: ");
    scanf("%d.%d", &i, &j);
    printf("left part: %d, right part: %d\n", i, j);

    return 0;
}