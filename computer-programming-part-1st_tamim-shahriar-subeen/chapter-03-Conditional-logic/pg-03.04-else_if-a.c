#include <stdio.h>

int main() {
    int n;

    n = 0;

    if (n < 0) {
        printf("The number is negative\n");
    }
    else if (n > 0) {
        printf("The number is pogative\n");
    }
    else {
        printf("The number is Zero\n");
    }

    return 0;
}