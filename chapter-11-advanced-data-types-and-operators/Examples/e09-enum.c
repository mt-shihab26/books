#include <stdio.h>

enum computer
{
    keyboard,
    CPU,
    screen,
    printer
};

int main()
{
    enum computer comp;

    comp = CPU;

    printf("%u\n", comp);

    return 0;
}