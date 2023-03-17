#include <stdio.h>

int main() {
    int *p, q;

    p = &q; // get q's address

    *p = 199; /*assign q a value using a pointer 
                also called Dereferencing and here * is Dereferencing operator*/

    printf("q's value is %d\n", q);

    return 0;
}