#include <stdio.h>

int a;
static int b;

void func(void)
{
    a = a+1;
    b = b+1;
}

int main(void)
{
    func();
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    
    return 0;
}