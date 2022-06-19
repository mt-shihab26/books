#include <stdio.h>

void f(void);

int main(void)
{
    f();
    f();
    f();

    return 0;
}

void f(void)
{
    int i = 10;

    printf("%d ", i);
}

// Date: Friday, April 02, 2021 | 15:32:40
