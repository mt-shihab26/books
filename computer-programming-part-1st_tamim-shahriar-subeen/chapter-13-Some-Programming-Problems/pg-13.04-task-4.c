#include <stdio.h>

int main() {
    int s = 18, i, j, k;

    for (i = 1; i <= 10; i++) {
        for (j = i; j > 0; j--) {
            printf("c");
        }
        for (k = s; k > 0; k--) {
            printf(" ");
        }
        for (j = i; j > 0; j--) {
            printf("c");
        }
        s -= 2;
        printf("\n");
    }

    return 0;
}