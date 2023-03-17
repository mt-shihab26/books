#include <stdio.h>

int main(void)
{
    char ch;

    for (ch = getchar(); ch != 'q'; ch = getchar()); // C allows null statements.
    printf("Found the q.\n");

    return 0;
}