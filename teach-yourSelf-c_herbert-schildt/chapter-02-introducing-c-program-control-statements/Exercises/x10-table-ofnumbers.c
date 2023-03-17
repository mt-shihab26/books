#include <stdio.h>

int main(void)
{
    int i;

    for (i=1; i<11; i++) {
        printf("%d\t%d\t%d\n", i, i*i, i*i*i);
    }

    return 0;
}