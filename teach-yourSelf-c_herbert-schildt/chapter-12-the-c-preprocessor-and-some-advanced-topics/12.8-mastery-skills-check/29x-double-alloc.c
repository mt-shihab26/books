#include <stdio.h>
#include <stdlib.h>

int main()
{
    double *d = (double *)malloc(sizeof(double));

    *d = 99.01;

    printf("%lf\n", *d);

    return 0;
}