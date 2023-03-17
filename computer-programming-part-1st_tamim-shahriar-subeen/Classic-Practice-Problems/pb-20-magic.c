#include <stdio.h>

int main() {
    int t, count_0, count_1, i;
    char str[52];
    scanf("%d", &t);
    while (t--) {
        scanf(" %s", str);
        count_0 = 0;
        count_1 = 0;
        for (i = 0; str[i] != '\0'; ) {
            if (str[i] == '1') {
                while (str[i] == '1') {
                    count_1 += 1;
                    i++;
                }
            }
            else if (str[i] == '0') {
                while (str[i] == '0') {
                    count_0 += 1;
                    i++;
                }
            }
            if (count_0 <= count_1) {
                continue;
            }
            else if (count_0 > count_1) {
                printf("MAGIC\n");
                break;
            }
        }
        if (count_0 <= count_1) {
            printf("NORMAL\n");
        }
    }
    return 0;
}