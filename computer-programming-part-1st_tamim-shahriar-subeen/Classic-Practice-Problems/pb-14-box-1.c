#include <stdio.h>

int main()
{
    int t, n, m, i, j = 1;

    scanf("%d", &t);
    while (j <= t) {
        scanf("%d", &n);
        m = n;
        while (n--) {
            for (i = 0; i < m; i += 1) {
                printf("*");
            } 
                printf("\n");
        }
        if (j != t){
            printf("\n");
        }
        j += 1;
    }

    return 0;
}