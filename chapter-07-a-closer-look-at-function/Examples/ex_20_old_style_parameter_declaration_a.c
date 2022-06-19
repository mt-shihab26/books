#include <stdio.h>

int area(int l, int w);

int main(void) 
{
    printf("area is %d\n", area(10, 13));
    return 0;
}

int area(l, w)
int l, w;
{
    return l*w;
}