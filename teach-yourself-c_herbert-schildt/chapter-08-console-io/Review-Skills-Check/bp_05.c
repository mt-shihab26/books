#include <stdio.h>

int rstrlen(char *c);
int i = 0;

int main(void) {
    printf("%d\n", rstrlen("good"));
}

int rstrlen(char *c) {
    if (*c != '\0') {
        i++;
        rstrlen(c+1);
    }
    return i;
}