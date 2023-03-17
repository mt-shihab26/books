#include <stdio.h>

int main() {
	int a, b, gcd, t, mul, lcm;

	printf("Enter two number for gcd: ");
	scanf("%d %d", &a, &b);
    mul = a * b;
	if (a == 0) gcd = a;
	else if (b == 0) gcd = b;
	else {
		while (b != 0) {
			t = b;
			b = a % b;
			a = t;
		}
		gcd = a;
	}
	lcm = mul / gcd;

    printf("LCM is %d\n", lcm);

	return 0;
}
