#include <stdio.h>

int get_a_char(void);

int main(void) {
    char ch;

    ch =  get_a_char();
    printf("%c", ch);
}

int get_a_char(void) {
    return 'a';
}