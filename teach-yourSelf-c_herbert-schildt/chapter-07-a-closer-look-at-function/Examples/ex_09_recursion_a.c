#include <stdio.h>

void recurse(int i);

int main(void) {
    recurse(0);

    return 0;
}

void recurse(int i) {
    if (i < 10) {
        printf("%d ", i);
        recurse(i+1);
    }
}

// Date: শুক্রবার, ফেব্রুয়ারী 26, 2021 | 00:13:28
