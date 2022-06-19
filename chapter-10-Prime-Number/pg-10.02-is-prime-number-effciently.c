#include <stdio.h>
#include <math.h>

int is_prime(int num) {
    int i, root;
	if (num < 2) {
		return 0;
	}
    if (num == 2) {
        return 1;
    }
    root = sqrt(num);
	for (i = 3; i < root; i += 2) {
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
