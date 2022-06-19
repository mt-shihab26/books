#include <stdio.h>

int main(void)
{
    int a, b;
    enum color {RED, GREED, BLUE};
    color c;

    a = 4; // right
    b = 2; // right 
    4 = a; // wrong
    (a + 1) = 3; // wrong
    b = (a + 2); // right
    b = (a + 2); // right
    a+b = a-b; // wrong
    c = red; // right
 
    green = c; // wrong


    return 0;
}