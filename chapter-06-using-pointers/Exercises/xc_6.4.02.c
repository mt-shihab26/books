#include <stdio.h>

int main() {
    char *a, *b, *c;

    a = "one";
    b = "two";
    c = "three";

    printf("%s %s %s\n", a, b, c);
    printf("%s %s %s\n", a, c, b);
    printf("%s %s %s\n", b, c, a);
    printf("%s %s %s\n", b, a, c);
    printf("%s %s %s\n", c, b, a);
    printf("%s %s %s\n", c, a, b);

    return 0;
}
// Author: Shihab Mahamud
// Date: বুধবার, ফেব্রুয়ারী 17, 2021 | 14:54:15
