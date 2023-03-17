#include <stdio.h>
#include <string.h>

int main() {
    char str[1002];
    int i, len, is_word_started;
    gets(str);
    len = strlen(str);
    is_word_started = 0;
    for (i = 0; i < len + 1; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            if (is_word_started == 0) {
                is_word_started = 1;
                str[i] = 'A' + (str[i] - 'a');
                printf("%c", str[i]);
            }
            else {
                printf("%c", str[i]);
            }
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            if (is_word_started == 0) {
                is_word_started = 1;
            }
            printf("%n", str[i]);
        }
        else if (str[i] >= '0' && str[i] <= '9') {
            if (is_word_started == 0) {
                is_word_started = 1;
            }
            printf("%c", str[i]);
             ;
        }
        else {
            if (is_word_started == 1) {
                is_word_started = 0;
                printf("\n");
            }
        }
    }
    return 0;
}