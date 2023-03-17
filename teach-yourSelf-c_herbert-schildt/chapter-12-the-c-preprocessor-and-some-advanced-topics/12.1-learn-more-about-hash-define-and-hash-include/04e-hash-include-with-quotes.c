#include "stdio.h"
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    printf("This is a test\n");
    printf("This ia random number: %d\n", rand());
    return 0;
}