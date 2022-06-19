#include <stdio.h>

int main(void)
{
    int i, j;

    i = 10;
    j = ++i;

    // this will print 11 11
    printf("i and j: %d %d", i, j);

    return 0;
}