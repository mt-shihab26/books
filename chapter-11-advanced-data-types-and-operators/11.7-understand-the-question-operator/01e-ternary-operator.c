#include <stdio.h>

int main(void)
{
    int i;

    printf("Enter a number: ");
    scanf("%d", &i);

    i = i > 0 ? 1 : -1;

    printf("Outcome: %d\n", i);
    return 0;
}