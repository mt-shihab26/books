#include <stdio.h>

int main(void)
{
    int three_d[3][3][3], i, j, k, sum;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            for (k = 0; k < 3; k++) {
                three_d[i][j][k] = (i+1) * (j+1) * (k+1);
                printf("%d ", three_d[i][j][k]);
            }
    // sum all elements
    sum = 0;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            for (k = 0; k < 3; k++)
                sum += three_d[i][j][k];
    printf("\n%d\n", sum);

    return 0;
}