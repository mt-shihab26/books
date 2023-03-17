#include <stdio.h>

int main(void)
{
    char ch;
    int i;

    printf("Enter a character: ");
    scanf("%c", &ch);
    printf("\n");

    /* display binary representation */
    for (int i = 128; i > 0; i /= 2)
    {
        if (i & ch)
            printf("1 ");
        else
            printf("0 ");
    }

    return 0;
}