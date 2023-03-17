#include <stdio.h>
#include <ctype.h>

void pr_str(const char *p);

int main(void) {
    char str[80];

    printf("Enter a string: ");
    gets(str);
    pr_str(str);

    return 0;
}

void pr_str(const char *p) {
    while (*p) {
        *p = toupper(*p); // this will not compile
        putchar(*p++);
    }
}