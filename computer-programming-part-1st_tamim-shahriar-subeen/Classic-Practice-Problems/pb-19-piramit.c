#include <stdio.h>

int main() {
    int t, n, temp, i, j, k;
    scanf("%d", &t);
    while (t--) {
        scanf(" %d", &n);
        for (i = 1, k = 1; i <= n; i++, k+=2) {
            temp = n-i;
            while (temp > 0) {
                printf(" ");
                temp--;
            }
            for (j = k; j > 0; j--) {
                printf("*");
            }
        printf("\n");
        }
        if (t != 0) {
            printf("\n");
        }
    }
    return 0;
}