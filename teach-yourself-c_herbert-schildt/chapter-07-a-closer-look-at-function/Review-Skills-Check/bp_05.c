#include <stdio.h>

int my_strlen(char *str) {
    int i;
    for (i = 1; str[i] != '\0'; i++);
    return i;
}

int main() {

    char *str = "Hello World";

    printf("%d\n", my_strlen(str));

    return 0;
}