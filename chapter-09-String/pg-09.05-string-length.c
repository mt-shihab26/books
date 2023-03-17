#include <stdio.h>

int string_length(char st[]) {
	int i, length = 0;

	for (i = 0; st[i] != '\0'; i++) {
		length += 1;
	}

	return length;
}

int main() {
	char country[100];
	int length;

	while (1 == scanf("%s", country)) {
		length = string_length(country);
		printf("length: %d\n", length);
	} 

	return 0;
}
