#include <stdio.h>

int main(void)
{
    int i, count;
    double d;
    char str[100];

    scanf("%d%lf%s%n", &i, &d, str, &count);
    printf("%d\n", count);

    return 0;
}