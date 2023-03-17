#include <stdio.h>

int main() {
    char str[80], *p;
    int i, spaces;

    p = str;

    printf("Enter a string: ");
    gets(str);

    spaces = 0;

    while (*p) {
        if (*p == ' ') {
            spaces++;
        }
        p++;
    }

    printf("Number of spaces: %d\n", spaces);

    return 0;
}