#include <stdio.h>
#include <math.h>

double hypot(double s1, double s2);

int main(void)
{
    printf("%f", hypot(12.2, 19.2));
    return 0;
}

double hypot(double s1, double s2)
{
    double h;
    h = s1*s2 + s2*s2;
    return sqrt(h);
}