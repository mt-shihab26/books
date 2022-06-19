#include <stdio.h>

int main() {
    int ara1[] = {3, 1, 5, 2, 4}, ara2[5];
    int i, min, j, min_indx;
    for (i = 0; i < 5; i += 1) {
        min = 10000;
        for (j = 0; j < 5; j += 1) {
            if (ara1[j] < min) {
                min = ara1[j];
                min_indx = j;
            }
        }
        ara2[i] = min;
        ara1[min_indx] = 10000;
        printf("%d\n", ara2[i]);
    }

    return 0;
}