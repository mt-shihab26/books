#include <stdio.h>

int main() {
    int intv = 100;
    int *p, **mp;

    p = &intv;
    mp = &p;

    printf("%p %p\n", &intv, *mp);
    printf("%p %p\n", &p, mp);
    printf("%p %p\n", &mp, &mp);

    printf("%p %p %p\n", &intv, p, mp);


    return 0;
}
// Author: Shihab Mahamud
// Date: বুধবার, ফেব্রুয়ারী 17, 2021 | 19:16:30
