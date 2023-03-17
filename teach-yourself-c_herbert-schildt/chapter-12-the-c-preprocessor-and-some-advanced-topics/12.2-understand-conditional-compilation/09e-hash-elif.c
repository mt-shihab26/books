#include <stdio.h>

#define NUM 2

int main()
{
#if NUM == 1
    printf("NUM is 1\n");
#elif NUM == 2
    printf("NUM is 2\n");
#elif NUM == 3
    printf("NUM is 3\n");
#elif NUM == 4
    printf("NUM is 4\n");
#endif
}