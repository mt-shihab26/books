#include <stdio.h>

int main() {
    int count[100][10];

    int *c;

    c = count;

    // count[44][8] = 99;

    *((int *)count + (44*10) + 8) = 99;

    return 0;
}