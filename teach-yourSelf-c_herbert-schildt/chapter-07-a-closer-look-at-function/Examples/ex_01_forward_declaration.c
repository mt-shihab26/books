#include <stdio.h>

double volume(); // old-style forward declaration for volume // it is not funtion prototype

int main() {
    double vol;

    vol = volume(12.2, 5.67, 9.03);
    printf("Volume: %f\n", vol);
    return 0;
}

// compute the volume of a cube

double volume(double s1, double s2, double s3) {
    return s1 * s2 * s3;
}