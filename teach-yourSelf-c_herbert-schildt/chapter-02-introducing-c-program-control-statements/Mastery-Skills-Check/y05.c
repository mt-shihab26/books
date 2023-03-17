#include <stdio.h>

int main(void)
{
    int i, j = 1;
    while (1) {
        if (j == 101) break;
        for (i = 1; i <= 5; i++) {
            printf("%d\t", j);
            j++;
        }
        printf("\n");
    }
    return 0;
}