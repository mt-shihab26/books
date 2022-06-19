#include <stdio.h>

int is_prime(int num) {
	if (num < 2) {
		return 0;
	}
	int i;
	for (i = 2; i < num; i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int n;
	while(1) {
		printf("Please enter a number (or 0 to exit):  ");
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		if (1 == is_prime(n)) {
			printf("%d is prime number\n", n);
		}
		else {
			printf("%d is not prime number\n", n);
		}
	}

	return 0;
}
