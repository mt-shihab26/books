#include <stdio.h>
#include <stdlib.h>

#define DEBUG
#define DEBUG2 1
#undef DEBUG

int main()
{
    int j = 20;
    if (!(j % 2))
    {
#ifdef DEBUG
        printf("j = %d\n", j);
#endif
    }

    if (!(j % 2))
    {
#if DEBUG2 == 1
        printf("j = %d\n", j);
#endif
    }

    printf("%s\n", __FILE__);
    
    return 0;
}