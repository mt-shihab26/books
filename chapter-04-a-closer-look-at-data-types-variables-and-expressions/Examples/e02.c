#include <stdio.h>

int main(void)
{
    short int i; // a signed short integer
    unsigned short int u; // an unsigned short integer

    u = 33000;
    i = u;

    printf("%hd %hu", i, u);
}