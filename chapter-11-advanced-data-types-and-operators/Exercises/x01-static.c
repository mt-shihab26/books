#include <stdio.h>

void sum_it(int value);

int main(void)
{
    sum_it(10);
    sum_it(20);
    sum_it(30);
    return 0;
}

void sum_it(int value)
{
    static int sum = 0;

    sum = sum + value;
    printf("Current value: %d\n", sum);
}