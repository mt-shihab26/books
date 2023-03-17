#include <stdio.h>
#include <math.h>

int is_prime(long long num) {
    int i;
	long long root;
	if (num < 2) {
		return 0;
	}
    if (num == 2) {
        return 1;
    }
	if (num == 3) {
		return 1;
	}
	if (num % 2 == 0) {
		return 0;
	}
    root = sqrt(num);
	for (i = 3; i <= root; i += 2) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}

int main() {
	int t;
	long long n;

	scanf("%d", &t);
	while(t--) {
		scanf(" %lld", &n);
		if (1 == is_prime(n)) {
			printf("%lld is prime number\n", n);
		}
		else {
			printf("%lld is not prime number\n", n);
		}
	}

	return 0;
}
