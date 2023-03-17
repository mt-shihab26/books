#include <stdio.h>

int main() {
    int v, *p;

    p = &v;

    *p = 100;

    printf("%d %d\n", v, *p);

    return 0;
}