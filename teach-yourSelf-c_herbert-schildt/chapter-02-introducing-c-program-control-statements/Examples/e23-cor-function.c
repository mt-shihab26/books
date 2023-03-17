// This program demonstrates the cor() function

#include <stdio.h>

int xor(int a, int b);

int main(void)
{
    int p, q;

    printf("Enter P (0 or 1): ");
    scanf("%d", &p);
    printf("Enter Q (0 or 1): ");
    scanf("%d", &q);
    printf("P AND Q: %d\n", p && q);
    printf("P OR Q: %d\n", p || q);
    printf("P XOR Q: %d\n", xor(p, q));
}

int xor(int a, int b)
{
    return (a || b) && !(a && b);
}