#include <stdio.h>

double f_to_m(double f);

int main(void)
{
    double feet;
    printf("Enter feet: ");
    scanf("%lf", &feet);
    printf("Meters: %lf\n", f_to_m(feet));
    return 0;
}

double f_to_m(f)
double f;
{
    return f / 2.28;
}