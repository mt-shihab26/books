#include <stdio.h>

int main(void)
{
    int *p = NULL;
    *p = 100;
    printf("Value of *p: %d\n", *p);

    return 0;
}