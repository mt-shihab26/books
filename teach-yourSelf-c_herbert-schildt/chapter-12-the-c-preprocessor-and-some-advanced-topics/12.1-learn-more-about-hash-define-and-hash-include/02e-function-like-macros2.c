#include "stdio.h"
#include <stdlib.h>
#include <time.h>

#define RANGE(i, min, max) ((i) < (min)) || ((max) < (i)) ? 1 : 0

int main(void)
{
    int r;

    /* print random number between 1 and 100 */

    srand(time(NULL));

    do
    {
        r = rand();
        printf("%d ", r);
    } while (RANGE(r, 1, 100));

    printf("%d\n", r);

    return 0;
}