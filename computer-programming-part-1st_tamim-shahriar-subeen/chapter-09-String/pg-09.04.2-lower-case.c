#include <stdio.h>

int main() {
	char country[] = "BANGlADESH";
	int i, len = 10;

	printf("%s\n", country);
	for (i = 0; i < 10; i += 1) {
		if (country[i] >= 'A' && country[i] <= 'Z') {
			country[i] = 'a' + (country[i] - 'A');
		}
	}
	printf("%s\n", country);

	return 0;
}
