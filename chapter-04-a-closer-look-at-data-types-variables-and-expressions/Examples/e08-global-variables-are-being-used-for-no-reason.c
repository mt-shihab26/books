#include <stdio.h>

int power(void);

int m, e;

int main(void)
{
    m = 2;
    e = 3;

    printf("%d raised to the %d power is %d", m, e, power());

    return 0;
}

// non-general version of power
int power(void)
{
    int temp, temp2;

    temp = 1;
    temp2 = e;
    for (; temp2 > 0; temp2--) temp *= m;

    return 0;
}