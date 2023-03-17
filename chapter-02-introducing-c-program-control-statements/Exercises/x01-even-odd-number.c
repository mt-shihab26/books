#include <stdio.h>

int main(void)
{
    int num;
    printf("Enter a Number: ");
    scanf("%d", &num);

    if (num % 2 == 0) printf("Even");
    if (num % 2 == 1) printf("Odd");

    return 0;
}