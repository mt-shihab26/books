#include <stdio.h>

int main() {
    int i, n, result;

    scanf("%d", &n);

    result = 0;

    for (i=1; i<=n; i++) {
        result = result + i;
    }
    
    return 0;
}