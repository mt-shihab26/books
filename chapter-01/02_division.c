#include <stdio.h>

int main() {
    int a = 10;
    int divisor = 2;
    int result = 0;

    while (a) {
        a = a - divisor;
        result = result + 1;
    }

    printf("the result is %d\n", result);

    return 0;
}