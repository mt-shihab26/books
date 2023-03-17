#include <stdio.h>

int main() {
    char *p, **mp, str[80];

    p = str;
    mp = &p;

    printf("Enter your name: ");
    gets(*mp);
    printf("Hi %s", *mp);

    return 0;
}
// Author: Shihab Mahamud
// Date: বুধবার, ফেব্রুয়ারী 17, 2021 | 19:07:06
