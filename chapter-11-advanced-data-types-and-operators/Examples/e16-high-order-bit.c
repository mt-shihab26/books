#include <stdio.h>

int main(void)
{
    short i = 1;
    i = i | 32768;
    printf("%hd\n", i);
    return 0;
}