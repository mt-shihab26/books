#include <stdio.h>

int main() {
    float *fp, **mfp, val;

    fp = &val;
    mfp = &fp;

    **mfp = 123.903;
    printf("%f %f\n", val, **mfp);

    return 0;
}
// Author: Shihab Mahamud
// Date: বুধবার, ফেব্রুয়ারী 17, 2021 | 19:03:55
