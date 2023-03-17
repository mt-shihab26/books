#include <stdio.h>

int main() {
    int numta[10][10];
    int row, cal, even_count, odd_count, total;

    for (row = 0; row < 10; row++) {
        for (cal = 0; cal < 10; cal++) {
            numta[row][cal] = (row+1)*(cal+1);
        }
    }
    even_count = 0;
    odd_count = 0;
    total = 0;
    for (row = 0; row < 10; row++) {
        for (cal = 0; cal < 10; cal++) {
            total += numta[row][cal];
            // printf("%d\t%d\n", numta[row][cal], total);
            if (numta[row][cal] % 2 == 0) {
                even_count += 1;
            }
            else {
                odd_count += 1;
            }
        }
    }
    printf("Even = %d\nOdd = %d\nTotal = %d\n", even_count, odd_count, total);

    return 0;
}