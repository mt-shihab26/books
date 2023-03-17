#include <stdio.h>

int main()
{
    int num1, num2, op;

    printf("Enter 1. Add or 2. Subtract: ");
    scanf("%d", &op);

    if (op == 1){
        printf("Enter a number for add: ");
        scanf("%d", &num1);
        printf("Enter a number2 for add: ");
        scanf("%d", &num2);
        printf("Addition is: %d", num1 + num2);
    }
    else {
        printf("Enter a number for subtract: ");
        scanf("%d", &num1);
        printf("Entre a number2 for subtract: ");
        scanf("%d", &num2);
        printf("Suctract: %d", num1 - num2);
    }

    return 0;
}