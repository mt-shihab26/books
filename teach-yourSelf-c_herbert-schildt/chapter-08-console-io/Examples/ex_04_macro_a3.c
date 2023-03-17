#include <stdio.h>

#define SMALL 1
#define MEDIUM SMALL+1
#define LARGE MEDIUM+1

int main(void)
{
    printf("%d %d %d\n", SMALL, MEDIUM, LARGE);
    return 0;
}