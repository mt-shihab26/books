#include <stdio.h>

void summation(int *p, int *q) {
    printf("%d + %d = %d\n",*p, *q, (*p) + (*q));
}

void subtrction(int *p, int *q) {
    printf("%d - %d = %d\n", *p, *q, (*p) - (*q));
}

void multiply(int *p, int *q) {
    printf("%d x %d = %d\n",*p, *q, (*p) * (*q));
}

void divition(int *p, int *q) {
    printf("%d / %d = %d\n",*p, *q, (*p) / (*q));
}

int main() {
    int *p, *q, a, b;

    p = &a;
    q = &b;

    a = 10;
    b = 5;

    summation(p, q);
    subtrction(p, q);
    multiply(p, q);
    divition(p, q);


    return 0;
}