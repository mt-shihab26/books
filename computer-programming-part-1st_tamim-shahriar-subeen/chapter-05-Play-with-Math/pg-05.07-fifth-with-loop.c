#include <stdio.h>

int main() {
	int i, n, sum;

	printf("Enter n = ");
	scanf("%d", &n);
	sum = 0;
	for (i = 1; i <= n; i += 1) {
		sum += i;
	}
	printf("Summation is %d\n", sum);

	return 0;
}
