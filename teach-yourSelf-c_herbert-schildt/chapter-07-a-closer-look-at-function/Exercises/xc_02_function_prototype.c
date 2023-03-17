#include <stdio.h>

float avg(void); // function prototype

int main() {
    printf("%f", avg());
    return 0;
}

float avg(void) {
    float sum = 0, temp;
    int t = 10;
    while (t--) {
        scanf("%f", &temp);
        sum += temp;
    }

    return sum / 10.0;
}


// Date: বৃহস্পতিবার, ফেব্রুয়ারী 25, 2021 | 23:42:24
