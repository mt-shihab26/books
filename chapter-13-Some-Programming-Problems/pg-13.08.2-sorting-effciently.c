#include <stdio.h>

int main() {
    int ara[] = {3, 1, 5, 2, 4};
    int i, min, j, index, temp;

    for (i = 0; i < 5; i += 1) {
        min = 1000;
        for (j = i; j < 5; j++) {
            if (ara[j] < min) {
                min = ara[j];
                index = j;
            }
        }
        temp = ara[i];
        ara[i] = min;
        ara[index] = temp;
    }
    for (i = 0; i < 5; i++) {
        printf("%d\n", ara[i]);
    }

    return 0;
}