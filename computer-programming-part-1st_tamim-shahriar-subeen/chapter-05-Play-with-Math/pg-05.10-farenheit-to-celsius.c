#include <stdio.h>

int main() {
	double farenheit, celsius;

	printf("Enter the Temperature in Farenheit: ");
	scanf("%lf", &farenheit);
	celsius = ((farenheit - 32 ) / 1.8);
	printf("Temperature is Celsius is %.2lf\n", celsius);

	return 0;
}
