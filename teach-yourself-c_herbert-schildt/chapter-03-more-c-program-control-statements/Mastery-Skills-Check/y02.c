#include <stdio.h>

int main(void)
{
    int ch;

    while (1) {
        printf("Enter a number(100 to exit): ");
        scanf(" %d", &ch);
        if (ch == 100) break;
        if (ch > 0)
            printf("%d is positive\n", ch);
        else 
            if (ch < 0)
                printf("%d is negative\n", ch);
            else 
                printf("It's Zero\n");
    }
    return 0;
}