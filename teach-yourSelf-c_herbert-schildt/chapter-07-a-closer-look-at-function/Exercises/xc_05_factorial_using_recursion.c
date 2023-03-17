#include <stdio.h>

int fact(int i, int r);

int sum = 1;

int main(void) {
    int n = fact(4, 4);
    printf("%d\n", n);
    return 0;
}

int fact(int i, int r){
    if (i > 1)
        fact(i-1, r);
    sum *= i;
    if (i == r) {
        return sum;
    }
    return 0;
}

// Date: শুক্রবার, ফেব্রুয়ারী 26, 2021 | 00:47:11
