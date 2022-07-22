// the non-generalized version

#include <stdio.h>

void soundspeed(void);

double distance;

int main(void)
{
    printf("Enter distance in feet: ");
    scanf("%lf", &distance);
    soundspeed();

    return 0;
}

void soundspeed(void)
{
    printf("Travel time: %f\n", distance / 1129);
}
