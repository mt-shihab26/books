#include <stdio.h>

int main(void)
{
    int num;

    while (1) {
        printf("Enter your number (0 to exit): ");
        scanf("%d", &num);
        if (num & 1)
            printf("%d is Odd\n", num);
        else
            printf("%d is Even\n", num);
        if (num == 0)
            break;
    }

    return 0;
}