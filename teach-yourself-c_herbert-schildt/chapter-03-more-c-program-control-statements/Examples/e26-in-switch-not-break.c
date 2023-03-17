#include <stdio.h>

int main(void)
{
    char ch;

    do {
        printf("\nEnter a character, q to quit: ");
        scanf(" %c", &ch);
        printf("\n");

        switch (ch) {
            case 'a': printf("Now is ");
            case 'b': printf("the time ");
            case 'c': printf("for all good man");
            case 'd': printf("The summer ");
            case 'e': printf("soldier ");
        }
    } while (ch != 'q');

    return 0;
}