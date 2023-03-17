#include <stdio.h>

#define ABS(x) (x) < 0 ? -(x) : (x)

int main()
{
    printf("%d %d %d\n", ABS(-12), ABS(0), ABS(11));
}