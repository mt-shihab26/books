#include <stdio.h>

void prompt(char *mag, char *str);

int main() {
    char str[100];
    prompt("Enter a string: ", str);
    printf("%s\n", str);
}

void prompt(char *mag, char *str) {
    printf("%s", mag);
    scanf("%s", str);
}

// Date: শুক্রবার, ফেব্রুয়ারী 26, 2021 | 18:55:44
