#include <stdio.h>

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);

    b != 0 ? printf("%d\n", a / b) : printf("b is zero\n");

    return 0;
}