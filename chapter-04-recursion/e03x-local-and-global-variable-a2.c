#include <stdio.h>

int x = 10;

void myfnc(void)
{
    int x; 

    x = 120;

    printf("myfnc, x = %d\n", x); // here x is local variable
}

int main(void)
{
    myfnc();

    printf("main, x = %d\n", x); // here x is global variable

    return 0;
}