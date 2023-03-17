#include <stdio.h>

int main() {
    int ara[5][5] = {{6, 4, 7, 8, 9}, {3, 7, 1, 9, 9}, {8, 6, 4, 2, 7}, {2, 4, 2, 5, 9}, {4, 1, 6, 7, 3}};
	int sum[5];
	int row, cal;
	for (row = 0; row < 5; row++) {
			sum[row] = 0;
			for (cal = 0; cal < 5; cal++) {
				sum[row] += ara[row][cal];
			}
			printf("Sum of row %d: %d\n", row+1, sum[row]);
	}
}
