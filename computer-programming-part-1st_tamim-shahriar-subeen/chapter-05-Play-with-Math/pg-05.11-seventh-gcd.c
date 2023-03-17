#include <stdio.h>

int main() {
	int a, b, i, gcd;

	printf("Enter two number: ");
	scanf("%d %d", &a, &b);
	if (a < b) {
		i = a;
	}
	else {
		i = b;
	}
	while (i >= 1) {
		if (a % i == 0 && b % i == 0) {
			gcd = i;
			break;
		}
		i -= 1;
	}
	printf("GCD is %d\n", gcd);
	

	return 0;
}
