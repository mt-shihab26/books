#include <stdio.h>

int main(void)
{
    struct s_type {
        int i;
        int j;
    } s;

    int i;
    i = 10;

    s.i = 100;
    s.j = 101;
    
    printf("%d %d %d\n", i, s.i, s.j);

    return 0;
}