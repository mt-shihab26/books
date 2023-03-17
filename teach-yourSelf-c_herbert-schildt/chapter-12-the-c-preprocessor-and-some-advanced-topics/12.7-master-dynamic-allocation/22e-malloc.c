#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p = (int *)malloc(sizeof(int));

    if (!p)
    {
        printf("Allocation Error");
        return 1;
    }
    *p = 10;
    printf("%d\n", *p);
    return 0;
}