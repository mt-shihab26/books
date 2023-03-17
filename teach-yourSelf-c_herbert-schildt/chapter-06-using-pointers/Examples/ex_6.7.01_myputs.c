#include <stdio.h>

void myputs(char *p);

int main() {
    
    myputs("This is a test");

    return 0;
}

void myputs(char *p) {
    while (*p) {
        printf("%c", *p); // Loop as long as p does not point to the null that terminates the string
        p++; // go to next charater
    }
    printf("\n");
}