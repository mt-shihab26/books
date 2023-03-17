#include <stdio.h>
#include <string.h>

int main() {
    int t, str_len, i, j, k, m, word_len;
    char str[1002], word[500][100];

    scanf("%d", &t);
    while (t--) {
        scanf(" %[^\n]", str);
        str_len = strlen(str);
        for (i = 0, j = 0, k = 0; i < str_len; i++) {
            if (str[i] == ' ') {
                j++;
                k = 0;
            }
            else {
                word[j][k] = str[i];
                k++;
            }
        }
        for (i = j; i >= 0; i--) {
            if (i == j) {
                printf("%s", word[i]);
            }
            else {
                printf(" %s", word[i]);
            }
        }
        printf("\n");
    }

    return 0;
}
// by Shihab Mahamud