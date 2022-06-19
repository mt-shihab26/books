#include <stdio.h>

int main(void)
{
    int i;

    // for
    for (i = 1; i <= 10 ; i++) printf("%d ", i);
    printf("\n");

    // while
    i = 1;
    while (i <= 10) {
        printf("%d ", i);
        i++;
    }
    printf("\n");

    // do
    i = 1;
    do {
        printf("%d ", i);
        i++;
    } while (i <= 10);
    printf("\n");

    return 0;
}