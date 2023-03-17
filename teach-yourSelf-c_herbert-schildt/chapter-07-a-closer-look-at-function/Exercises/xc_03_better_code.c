#include <stdio.h>

double myfunc(double n); // better prototyping

int main(void) {
    printf("%f", myfunc(10.2));

    return 0;
}

double myfunc(double num) {
    return num / 2.0;
}


// Date: বৃহস্পতিবার, ফেব্রুয়ারী 25, 2021 | 23:47:28
