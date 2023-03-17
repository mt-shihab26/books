#include <stdio.h>

void r(int i);

int main(void)
{
    r('a');
    printf("\n");
}

void r(int i)
{
    printf("%c ", i);
    if (i != 'z'){
        r(i+1);
    }
}