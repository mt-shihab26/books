#include <stdio.h>

int main() {
    char ch = 'a';

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        printf("%c is vowels\n");
    }
    else {
        printf("%c is consonants\n");
    }

    return 0;
}