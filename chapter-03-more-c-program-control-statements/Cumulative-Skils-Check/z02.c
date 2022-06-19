#include <stdio.h>

int main(void)
{
    int i, j, k;

    for (k = 0; k < 10; k++) {
        printf("Enter first number: ");
        scanf("%d", &i);

        printf("Enter second number: ");
        scanf("%d", &j);

        if (j) printf("%d\n", i/j);
        else printf("Cannot divide by zero\n");
    }
    return 0;
}