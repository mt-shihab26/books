#include <stdio.h>
#include <string.h>

int count_number(char str[]) {
    int len, count = 0, i;
    len = strlen(str);
    for (i = 0; i < len; i++) {
        if (str[i] == ' ' && str[i - 1] != ' ') {
            count += 1;
        }
    }
    return count + 1;
}

int main() {
    int t, len, count;
    char str[100000];

    scanf("%d", &t);
    while(t--) {
        scanf(" %[^\n]", str);
        count = count_number(str);
        printf("%d\n", count);
    }
}