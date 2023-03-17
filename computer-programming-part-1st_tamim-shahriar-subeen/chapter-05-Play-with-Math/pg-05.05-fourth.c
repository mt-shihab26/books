#include <stdio.h>

int main() {
	double t, v, _2t;

	printf("t = ");
	scanf("%lf", &t);
	printf("v = ");
	scanf("%lf", &v);

	_2t = 2 * t * v;

	printf("2t = %.2lf\n", _2t);

	return 0;
}
