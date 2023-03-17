#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_with_range(int low, int high)
{
    return ((rand() % (high - low + 1)) + low);
}

int main(void)
{
    time_t t;
    srand((unsigned)time(&t));
    printf("%d\n", rand_with_range(0, 100));

    return 0;
}