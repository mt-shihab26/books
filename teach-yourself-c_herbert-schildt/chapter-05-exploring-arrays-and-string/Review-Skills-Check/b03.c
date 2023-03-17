#include <stdio.h>

int main(void)
{
    long l;
    short s;
    double d;

    printf("Enter long: ");
    scanf("%ld", &l);
    printf("Enter short: ");
    scanf("%hd", &s);
    printf("Enter double: ");
    scanf("%lf", &d);

    printf("%ld %d %lf", l, s, d);

    return 0;
}