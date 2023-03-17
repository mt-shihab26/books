#include <stdio.h>

int main(void)
{
    int i = 100;
    int j = 12987;

    printf("%d\n", i);

    i = i ^ j;
    printf("%d\n", i);

    i = i ^ j;
    printf("%d\n", i);
}