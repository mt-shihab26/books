#include <stdio.h>

int main() {
    char str[] = "Pointers are fun";
    char *p;
    int i;

    p = str;

    // loop until null is found
    for (i = 0; p[i]; i++) 
        printf("%c", p[i]);
    
    printf("\n");

    return 0;
}