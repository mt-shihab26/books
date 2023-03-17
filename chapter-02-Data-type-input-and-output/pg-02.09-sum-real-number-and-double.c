#include <stdio.h>

int main() {
	double a, b, sum; // double = 8 Byte = 64bit

	a = 9.5;
	b = 8.743;

	sum = a + b;

	printf("Sum is: %lf\n", sum);
	printf("Sum is: %0.2lf\n", sum);

	return 0;
}
