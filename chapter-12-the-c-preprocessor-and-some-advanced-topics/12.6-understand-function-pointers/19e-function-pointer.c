#include <stdio.h>

int sum(int a, int b)
{
    return a + b;
}

int main(void)
{
    int (*p)(int, int) = sum;

    int result = (*p)(10, 20);
    printf("%d\n", result);

    result = p(10, 10);
    printf("%d\n", result);

    result = sum(10, 100);
    printf("%d\n", result);

    result = (*sum)(10, 200);
    printf("%d\n", result);

    return 0;
}