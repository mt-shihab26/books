#include <stdio.h>

// Shows how all pointer arithmetic is relativr to the base type of the pointer

int main() {
    char *cp, ch;
    int *ip, i;
    float *fp, f;
    double *dp, d;

    cp = &ch;
    ip = &i;
    fp = &f;
    dp = &d;

    // Print the current values
    printf("%p %p %p %p\n", cp, ip, fp, dp);

    //Now increment them by one
    cp++;
    ip++;
    fp++;
    dp++;

    //Print their new values
    printf("%p %p %p %p\n", cp, ip, fp, dp);

    return 0;
}