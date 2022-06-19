#include <stdio.h>

int main() {

    int *p, q;

    q = 199; // assign

    p = &q; // assign p the address of q

    printf("%d\n", *p); // display q's value using pointer

    return 0;
}