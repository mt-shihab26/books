#include <stdio.h>

void line(void);

int main() {
    line();
    return 0;
}

void line(void) {
    int i;
    for (i = 0; i < 80; i++)
        printf(".");
}