#include <stdio.h>

void rcopy(char *s1, char *s2);

int main(void) {
    char str[80];
    rcopy(str, "this is a test");

    printf("%s", str);

    return 0;
}

// Copy s2 to s1 using recursion

void rcopy(char *s1, char *s2) {
    if (*s2) { // if not at end of s2
        *s2++ = *s1++;
        rcopy(s1, s2);
    }
    else
        *s1 = '\0'; // null terminate the string
}

// Date: শুক্রবার, ফেব্রুয়ারী 26, 2021 | 00:17:59
