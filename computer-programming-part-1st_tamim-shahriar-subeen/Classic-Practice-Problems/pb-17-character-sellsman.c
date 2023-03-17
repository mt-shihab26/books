#include <stdio.h>

int main() {
    int t, count, i;
    char str[1002];
    scanf("%d", &t);
    while (t--) {
        count = 0;
        scanf(" %[^\n]", str);
        for (i = 0; str[i] != '\0'; ) {
            if (str[i] == ' ') {
                while (str[i] == ' ') {
                    i++;
                }
                count += 420;
            }
            else {
                i++;
            }
        }
        printf("%d\n", count+420);
    }

    return 0;
}