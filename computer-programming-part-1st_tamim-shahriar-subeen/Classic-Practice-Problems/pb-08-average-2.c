#include <stdio.h>

int main() {
    int t, len, i;
    int marks[1000];
    double result, sum;

    scanf("%d", &t);
    while (t--) {
        sum = 0;
        scanf(" %d", &len);
        for (i = 0; i < len; i++) {
            scanf("%d", &marks[i]);
            sum += marks[i];
        }
        result = sum / len;
        printf("%.2lf\n", result);
    }

    return 0;
}