#include <stdio.h>

void show_binary(unsigned u)
{
    unsigned n;

    for (n = 32768; n; n >>= 1)
    {
        if (u & n)
            printf("1 ");
        else
            printf("0 ");
    }
    printf("\n");
}

int main(void)
{
    unsigned short u = 45678;

    show_binary(u);
    u = u << 1;
    show_binary(u);
    u = u >> 1;
    show_binary(u);

    return 0;
}