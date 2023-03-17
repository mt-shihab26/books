#include <stdio.h>

int main() {
    int t, i;
    char str[52];

    scanf("%d", &t);
    while (t--) {
        scanf(" %[^\n]", str);
        for (i = 0; str[i] != '\0'; i++) {
            if (str[i] == 'L') {
                str[i] = str[i-1];
            }
            else if (str[i] == 'R') {
                str[i] = str[i+1];
            }
        }
        printf("%s\n", str);
    }
}