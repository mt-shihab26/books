#include <stdio.h>

int main() {
	int i, j, k, l, m = 11;
	int a, b, c, d, e;

	for (i = 0; i < 6; i++) {
		for (k = i; k > 0 && i != 0; k--) {
			printf(" ");
		}
		for (j = m; j > 0; j--) {
			printf("c");
		}
		m -= 2;
		printf("\n");
	}
	d = 3;
	for (a = 4; a >= 0; a--) {
		for (b = a; b >= 1; b--) {
			printf(" ");
		}
		for (c = d; c > 0; c--) {
			printf("c");
		}
		d += 2;
		printf("\n");
	}

	return 0;
}
