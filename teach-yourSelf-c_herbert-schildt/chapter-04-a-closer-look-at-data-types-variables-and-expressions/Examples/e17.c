#include <stdio.h>

int x = 10; //initialize global variable

int myfunc(int i);

int main(void)
{
    // initialize a local variable using a global variable
    int y = x;

    // initialize a local variable using a global variable
    int z = myfunc(y);

    printf("%d %d\n", y, z);

    return 0;
}

int myfunc(int i)
{
    return i/2;
}

// Date: Friday, April 02, 2021 | 15:35:47
