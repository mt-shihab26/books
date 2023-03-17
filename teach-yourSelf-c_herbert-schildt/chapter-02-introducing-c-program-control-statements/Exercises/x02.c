#include <stdio.h>

int main()
{
    int num1, num2, choose;

    printf("Enter first number: ");
    scanf("%d", &num1);

    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Enter 0. add or 1. multiply: ");
    scanf("%d", &choose);

    if (choose == 0) printf("Added = %d", num1+num2);
    else printf("Multiply = %d", num1*num2);

    return 0;
}