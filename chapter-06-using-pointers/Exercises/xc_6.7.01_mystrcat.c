#include <stdio.h>
#include <string.h>

void mystrcat(char *des, char *sou) {
    //find the end of des;
    while(*des)
        des++;

    // concatenate the string
    while(*sou)
        *des++ = *sou++;

    //add the null terminator
    *des = '\0';

    /* My solution
    int len = strlen(des);
    while(*sou) {
        des[len] = *sou++;
        len++;
    }
    des[len] = '\0'; */
}

int main() {

    char des[100] = "Hello ", sou[100] = "World";

    mystrcat(des, sou);

    printf(des);

    return 0;
}