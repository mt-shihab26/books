#include <stdio.h>

int main() {
    int a[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int *p;

    p = a; // assign p the address of start of a

    //this prints a's first, second and third elements
    printf("%d %d %d\n", *p, *(p+1), *(p+2));

    //this does the same thing using a
    printf("%d %d %d\n", a[0], a[1], a[2]);

    return 0;
}