#include <stdio.h>

int add(int a, int b)
{
    return a * b;
}

int main(void)
{
    int lenght, i, sum = 0, tmp;

    printf("Enter number of integer: ");
    scanf("%d", &lenght);
    for (i = 0; i < lenght; i++) {
        printf("Enter Number %d: ", i+1);
        scanf("%d", &tmp);
        printf("Number %d = %d\n", i+1, tmp);
        sum = add(sum, tmp);
    }

    printf("The average is %lf\n", (double)sum / lenght);

    return 0;
}