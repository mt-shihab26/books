#include <stdio.h>

int main()
{
    int decimal, binary[100], i, len;

    printf("Enter Decimal number: ");
    scanf("%d", &decimal);

    i = 0;
    while (decimal >= 0) {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
        if (decimal == 0) {
            break;
        }
    }
    binary[i] = '\0';
    len = i - 1;

    printf("The Binary number: ");
    for (i = len; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");

    return 0;
}