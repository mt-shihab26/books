#include <stdio.h>

union i_to_c {
    char c[2];
    short int i;
} ic;

int main(void) {
    printf("Enter an integer ");
    scanf("%hd", &ic.i);
    printf("Character representation fo each byte: %c %c", ic.c[0], ic.c[1]);
    return 0;
}