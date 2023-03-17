#include <stdio.h>
#include <string.h>

int main() {
    int t, count, len, i, count_more;
    char number[10];

    scanf("%d", &t);
    while (t--) {
        count = 0;
        count_more = 0;
        scanf(" %[^\n]", number);
        len = strlen(number);
        for (i = 0; i < len; i++) {
            count += (number[i] - '0');
        }
        if (count == 0) {
            printf("1\n");
        }
        else {
            for (i = 0; i < len; ){
                if (number[i] == '0') {
                    while (number[i] == '0') {
                        i++;
                    }
                }
                else{
                    count_more++;
                    i++;
                }
            }
            printf("%d\n", count_more);
        }
    }

    return 0;
}