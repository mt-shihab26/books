#include <stdio.h>

// this is volume()'s full prototype
double volume(double s1, double s2, double s3);

int main() {
    double vol;

    vol = volume(12.2, 5.67, 9.03, 10.2); // error
    printf("Volume: %f", vol);

    return 0;
}

// Compute the volume of a cube
double volume(double s1, double s2, double s3) {
    return s1 * s2 * s3;
}