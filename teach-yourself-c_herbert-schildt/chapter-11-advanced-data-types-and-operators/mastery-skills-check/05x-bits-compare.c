#include <stdio.h>

int main(void)
{
    char ch1, ch2;
    char mask, i;

    printf("Enter two characters: ");
    scanf("%c %c", &ch1, &ch2);

    mask = 1;
    for (i = 0; i < 8; i++)
    {
        if ((mask & ch1) && (mask & ch2))
            printf("bits %d the same\n", i);
        mask <<= 1;
    }

    return 0;
}