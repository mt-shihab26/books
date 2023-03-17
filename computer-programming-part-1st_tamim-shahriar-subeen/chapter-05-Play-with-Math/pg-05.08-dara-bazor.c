#include <stdio.h>

int main() {
    int i, n, sum;

    printf("Enter n = ");
    scanf("%d", &n);
    sum = 0;
    for (i = 1; i <= n; i += 2) {
        //printf("%d\n", i);
        sum = sum + i;
    }
    printf("The summation is %d\n", sum);

    return 0;
}