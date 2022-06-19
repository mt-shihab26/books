#include <stdio.h>

int main(void)
{
    unsigned int u;

    printf("Enter hexadecimal number: ");
    scanf("%x", &u);
    printf("Decimal equivalent: %u\n", u);

    return 0;
}