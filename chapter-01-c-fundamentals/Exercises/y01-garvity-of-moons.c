#include <stdio.h>

float gravity_of_moons(float earths_weight);

int main(void)
{
    float weigth;
    printf("Enter your weigth: ");
    scanf("%f", &weigth);
    gravity_of_moons(weigth);

    return 0;
}

float gravity_of_moons(float earths_weight)
{
    printf("%.2fN", (9.8*earths_weight)/6.0);
}