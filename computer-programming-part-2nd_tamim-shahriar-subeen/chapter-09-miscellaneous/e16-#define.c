#include <stdio.h>
#define ip int *

int main(int argc, char **argv)
{
    int *a;     // a is integer pointer
    ip b;       // b is also an integer pointer
    ip c, d;    // c is an integer pointer
                // BUT, d is only an integer
    return 0;
}