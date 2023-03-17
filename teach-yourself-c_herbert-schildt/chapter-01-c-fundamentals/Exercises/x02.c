#include <stdio.h>

int main(void)
{
    float num1, num2, sum;

    printf("Entar Number1: ");
    scanf("%f", &num1);

    printf("Enter Number2: ");
    scanf("%f", &num2);

    sum = num1 + num2;

    printf("The sum is: %f", sum);
    
    return 0;
}