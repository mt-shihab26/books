#include <stdio.h>

void soundspeed(double distance);

int main(void)
{
    double distance;

    printf("Enter distance in feet: ");
    scanf("%lf", &distance);
    soundspeed(distance);

    return 0;
}

void soundspeed(double distance)
{
    printf("Travle time: %f", distance / 1129);
}