#include <stdio.h>

int *init(int x);

int main(void) {
    int *p;

    p = init(110); // return pointer
    printf("count (through p) is %d", *p);

    return 0;
}

int *init(int x) {
    int count;
    count = x;

    return &count; // return a pointer
}

// Date: বৃহস্পতিবার, ফেব্রুয়ারী 25, 2021 | 23:14:05
