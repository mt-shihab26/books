#include <stdio.h>

int main()
{
    int t, n, i = 1, j;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        printf("Case %d: ", i);
        for (j = 1; j <= n; j += 1) {
            if (n % j == 0) {
                if (j != n) {
                    printf("%d ", j);
                }
                else {
                    printf("%d", j);
                }
            }
        }
        printf("\n");
        i += 1;
    }

    return 0;
}