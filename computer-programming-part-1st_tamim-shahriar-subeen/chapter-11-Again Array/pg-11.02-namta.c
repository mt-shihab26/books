#include <stdio.h>

int main() {
    int numta[10][10];
    int row, cal;

    for (row = 0; row < 10; row++) {
        for (cal = 0; cal < 10; cal++) {
            numta[row][cal] = (row+1)*(cal+1);
            printf("%d x %d = %d\n", row+1, cal+1, numta[row][cal]);
        }
        printf("\n");
    }

    return 0;
}