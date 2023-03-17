#include <stdio.h>

int main() {
	int a; // int -> =4Byte = 32 bit = 4294967296 = -2147483648 to 2147483647

	a = 1000;
	printf("Value of a is %d\n", a);

	a = -21000;
	printf("Value of a is %d\n", a);

	a = 10000000;
	printf("Value of a is %d\n", a);
	
	a = -10000000;
	printf("Value of a is %d\n", a);

	a = 100020004000503;
	printf("Value of a is %d\n", a);

	a = -4325987632;
	printf("Value of a is %d\n", a);


	return 0;
}
