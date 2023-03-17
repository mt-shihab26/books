#include <stdio.h>

int main(void)
{
    int i;
    char ch;

    // display all numbers that are multiples of 6
    for (i = 1; i < 10000; i++) {
        if (!(i%6)) {
            printf("%d more? (Y/N)", i);
            scanf("%c ", &ch);
            if (ch == 'N') break; // stop the loop
            printf("\n");
        }
    }
}