#include <stdio.h>

int main(void)
{
    int n, count, i;

    scanf("%d", &n); 
    count = 0;

    while (n) {
        if (n & 1) count++;
        n = n >> 1;
    }
    printf("Number of 1: %d\n", count);
    return 0;
}