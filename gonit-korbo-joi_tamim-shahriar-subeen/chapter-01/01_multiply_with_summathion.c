#include <stdio.h>

int main() {
    int n = 100, m = 99, result = 0, i;
    for (i = 1; i <= m; i++) {
        result += n;
    }
    printf("%d %d\n", result, m*n);

    return 0;
}