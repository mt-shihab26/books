#include <stdio.h>

int main() {
    double num1, num2, result;

    printf("Please enter a number: ");
	scanf("%lf", &num1);
	printf("Please enter another number: ");
	scanf("%lf", &num2);

    result = num1 + num2;
    printf("%lf + %lf = %lf\n", num1, num2, result);
    
    result = num1 - num2;
    printf("%lf - %lf = %lf\n", num1, num2, result);

    result = num1 * num2;
    printf("%lf * %lf = %lf\n", num1, num2, result);
    
    result = num1 / num2;
    printf("%lf / %lf = %lf\n", num1, num2, result);

    return 0;
}