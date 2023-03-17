#include <stdio.h>

int main(void)
{
    char ch;

    do {
        ch = getchar();
    } while (ch!='q');

    printf("Found the q.\n");

    return 0;
}