#include <stdio.h>

int sum_of_n(int n)
{
    if (n == 0)
        return 0;
    int nth_num = sum_of_n(n-1);
    printf("%d + ", n);
    return n+nth_num;
}

int main(void)
{
    int n;

    scanf("%d", &n);
    printf("\nsum of 1 to %d is %d", n, sum_of_n(n));

    return 0;
}