#include <stdio.h>

int main(void)
{
    int i, j;

    i = 10;
    j = i++;

    // this will print 11 10
    printf("I and J; %d %d", i, j);

    return 0;
}