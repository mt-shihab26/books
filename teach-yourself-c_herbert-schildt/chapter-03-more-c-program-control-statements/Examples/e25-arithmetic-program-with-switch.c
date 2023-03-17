#include <stdio.h>

int main(void)
{
    int a, b;
    char ch;

    printf("Do you want to: \n");
    printf("Add, Subtract, Multiply or Divide?\n");
    // force user to enter a valid response
    do {
        printf("Do you want to:\n");
        ch = getchar();
    } while (ch != 'A' && ch != 'S' && ch != 'M' && ch != 'D');
    printf("\n");

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    switch (ch) {
        case 'A' : printf("%d", a+b);
            break;
        case 'S' : printf("%d", a-b);
            break;
        case 'M' : printf("%d", a*b);
            break;
        case 'D' : if (b != 0) printf("%d", a/b);
            break;
    }

    return 0;
}