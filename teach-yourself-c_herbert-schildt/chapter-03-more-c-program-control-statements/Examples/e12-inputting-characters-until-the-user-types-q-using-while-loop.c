#include <stdio.h>

int main(void)
{
    char ch;

    ch = getchar();

    while(ch != 'q') ch = getchar();
    printf("Found the q.\n");

    return 0;
}