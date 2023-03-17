#include <stdio.h>

// typedef old-name new-name

typedef signed char smallint;

int main(void)
{
    smallint i;
    for (i = 0; i < 10; i++)
    {
        printf("%d ", i);
    }
}