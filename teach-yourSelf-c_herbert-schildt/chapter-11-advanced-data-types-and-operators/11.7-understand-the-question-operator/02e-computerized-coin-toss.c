#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int i;

    srand(time(NULL));

    // i = rand() % 2 ? 1 : 0;

    // if (i)
    //     printf("Heads");
    // else
    //     printf("Tails");

    rand() % 2 ? printf("Heads") : printf("Tails");

    printf("\n");

    return 0;
}