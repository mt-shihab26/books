#include <stdio.h>
#include <string.h>

void ds(char *str);

int main(void) {
    char *str = "This is a test";
    int len = strlen(str);
    ds(str);
    return 0;
}

void ds(char *str) {
    printf("%c", *str);
    if (*str) {
        ds(str+1);
    }

}


// Date: শুক্রবার, ফেব্রুয়ারী 26, 2021 | 00:59:48
