#include <stdio.h>

void f2(int b);
void f1(int a);

int main(void) {
    f1(30);

    return 0;
}

void f1(int a) {
    if (a)
        f2(a-1);
    printf("%d ", a);
}

void f2(int b) {
    printf(".");
    if (b)
        f1(b-1);
}


// Date: শুক্রবার, ফেব্রুয়ারী 26, 2021 | 00:37:37
