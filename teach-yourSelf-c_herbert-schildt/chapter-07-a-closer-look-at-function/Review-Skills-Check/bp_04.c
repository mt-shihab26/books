#include <stdio.h>

int main() {
    float f, *fp;

    fp = &f;

    *fp = 1.222323;

    printf("%f\n", f);

    return 0;
}