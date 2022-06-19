#include <stdio.h>

int main(void)
{
    int n, x, s;

    while (1) {
        printf("Enter your number (0 to exit): ");
        scanf("%d", &n);
        if (n == 0)
            break;
        printf("How many bits you want to shift right? ");
        scanf("%d", &x);

        s = n >> x;

        printf("Result is %d\n\n", s);
    }
}