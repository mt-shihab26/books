#include <stdio.h>

#define MAX(i, j) i > j ? i : j
#define MAX2(i, j) ((i) > (j) ? (i) : (j))

int main(void)
{
    printf("%d\n", MAX(1, 2));
    printf("%d\n", MAX(1, -1));

    /* this statement does not work correctly */

    // printf("%d\n", MAX(100 && -1, 0));
    // printf("%d\n", 100 && -1 > 0 ? 100 && -1 : 0)

    // now it works
    printf("%d\n", MAX2(100 && -1, 0));

    return 0;
}
