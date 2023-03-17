#include <stdio.h>

int main() {
	int i, j;

	for (i = 7; i > 0; i--) {
		for (j = i; j > 0; j--) {
			printf("c");
		}
		printf("\n");
	}
	for (i = 2; i <= 7; i++) {
		for (j = i; j > 0; j--) {
			printf("c");
		}
		printf("\n");
	}
	
	return 0;
}
