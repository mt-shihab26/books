#include <stdio.h>

int main() {
    char *p, str[80] = "This is a test";

    p = str;

    printf("%c %c %c %c\n",str[2], *(str+2), p[2], *(p+2));

    return 0;
}