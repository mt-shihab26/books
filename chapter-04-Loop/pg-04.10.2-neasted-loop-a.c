#include <stdio.h>

int main() {
	int n, m, i;

	for (n = 1; n <= 20; n += 1) {
		m = 0;
		for (i = 1; i <= 10; i += 1) {
			m += n;
			printf("%d x %d = %d\n", n, i, m);
		}
		printf("\n");
	}

	return 0;
}
