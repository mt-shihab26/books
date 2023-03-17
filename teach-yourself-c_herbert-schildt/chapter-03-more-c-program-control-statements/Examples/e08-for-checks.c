#include <stdio.h>
#include <curses.h>

int main(void)
{
    int i;
    char ch;

    ch = 'a'; // it give ch an initial value

    for (i=0; ch != 'q'; i++) {
        printf("pass: %d\n", i);
        ch = getchar();
    }
    return 0;
}