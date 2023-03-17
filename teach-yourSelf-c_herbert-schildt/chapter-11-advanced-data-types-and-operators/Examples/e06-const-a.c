#include <stdio.h>

int main(void) {
    const int i = 10;

    i = 20; // this is wrong

    printf("%d", i);

    return 0;
}