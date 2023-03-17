#include <stdio.h>

int main() {
    int t, temp;
    int positive = 0, negative = 0;

    scanf("%d", &t);
    while (t--) {
        scanf(" %d", &temp);
        if (temp > 0) {
            positive += 1;
        }
        else if (temp < 0) {
            negative += 1;
        }
    }
    printf("%d %d\n", positive, negative);

    return 0;
}