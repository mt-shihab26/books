#include <stdio.h>

int main() {
    int i, j, m = 7, k, l;

    for (i = 0; i < 7; i++) {
        for (j = i; j > 0 && i != 0; j--) {
            printf(" ");
        }
        for (k = m; k > 0; k--) {
            printf("c");
        }
        printf("\n");
        m--;
    }
    for (i = 2; i <= 7; i++) {
        for (k = 7-i; k > 0; k--) {
            printf(" ");
        }
        for (l = i; l > 0; l--) {
            printf("c");
        }
        printf("\n");
    }

    return 0;
}