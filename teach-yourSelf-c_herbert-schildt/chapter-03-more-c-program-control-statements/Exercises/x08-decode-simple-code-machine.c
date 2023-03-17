#include <stdio.h>

int main(void)
{
    char ch;
    printf("Enter a messages: ");

    ch = getchar();
    while (ch  != '\n') {
        printf("%c", ch-1);
        ch = getchar();
    }

    printf("\n");

    return 0;
}