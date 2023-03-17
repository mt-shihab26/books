#include<stdio.h>

int main() {
	int t, i, marks[5], sum;
	scanf("%d", &t);
	while (t--) {
		sum = 0;
		for (i = 0; i < 5; i++) {
			scanf(" %d", &marks[i]);
			sum += marks[i];
		}
		printf("%d\n", (sum / 5));
	}

	return 0;
}
