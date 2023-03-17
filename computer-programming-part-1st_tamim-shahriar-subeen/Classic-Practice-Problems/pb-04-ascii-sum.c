#include <stdio.h>

int main() {
    int t, sum, i;
    char str[4];

    scanf("%d", &t);
    while (t--) {
        sum = 0;
        scanf(" %[^\n]", str);
        for (i = 0; i < 3; i++) {
            sum += str[i];
        }
        printf("%d\n", sum);
    }
   
}