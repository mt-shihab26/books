#include <stdio.h>

void f(void);

int main(void)
{
    #define LIGHTSPEED 186000

    f();

    return 0;
}

void f(void)
{
    printf("%d\n", LIGHTSPEED);
}