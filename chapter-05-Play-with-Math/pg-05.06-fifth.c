#include <stdio.h>

int main() {
	double n, sum;

	printf("Enter n = ");
	scanf("%lf", &n);
	sum = n * (n+1) / 2;
	printf("sum = %.2lf\n", sum);

	return 0;
}
