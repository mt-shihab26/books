#include <stdio.h>

void pr_str(const char *p);

int main(void) {
    char str[80];

    printf("Enter a string: ");
    gets(str);

    pr_str(str);

    return 0;
}

void pr_str(const char *p) {
    // putchar(*p++);
    putchar(*p);
    p++;
    while (*p) putchar(*(p++)); // this is ok

}