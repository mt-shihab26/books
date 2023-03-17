#include <stdio.h>

int main() {
    int *p, q;

    p = &q;

    q = 1;
    printf("%p ", p);

    *p++; // this will not increment q;
    printf("%d %p\n", q, p);

    return 0;
}