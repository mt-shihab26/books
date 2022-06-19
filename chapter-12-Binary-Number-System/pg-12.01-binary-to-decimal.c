#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char binary[100];
    int len, position, decimal = 0, temp, i;

    printf("Enter the Binary number: ");
    scanf("%s", binary);

    len = strlen(binary);
    position = len - 1;

    for (i = 0; i < len; i++) {
        temp = binary[i] - '0';
        decimal += (temp * pow(2, position));
        position--;
    }
    printf("The Decimal Value is: %d\n", decimal);

    return 0;
}