#include <stdio.h>

void outnum(int num);

int main(void)
{
    outnum(10.0);

    return 0;
}

void outnum(int num)
{
    printf("%d", num);
}