#include <stdio.h>

int main() {
    int number, i, factorial = 1;
    scanf("%d", &number);
    for (i = number; i > 0; i--) {
        factorial *= i;
    }
    printf("Factorial of %d! is %d\n", number, factorial);

    return 0;
}