#include <stdio.h>

void recurse(int i);

int main(void) {
    recurse(0);

    return 0;
}

void recurse(int i) {
    if (i < 10) {
        recurse(i+1); // recursive call
        printf("%d ", i);
    }
}

// Date: বৃহস্পতিবার, ফেব্রুয়ারী 25, 2021 | 23:59:13
