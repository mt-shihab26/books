#include <stdio.h>
int find_min(int ar[], int x);
int find_max(int ar[], int x);
int find_sum(int ar[], int x);
int find_avrg(int ar[], int x);

int main() {
	int ara[] = {-100, 0, 53, 22, 83, 23, 89, -132, 201, 3, 85};
	int n = 11;
	int max = find_max(ara, n);
	printf("Max = %d\n", max);

	int min = find_min(ara, n);
	printf("Min = %d\n", min);

	int sum = find_sum(ara, n);
	printf("Sum = %d\n", sum);

	int average = find_avrg(ara, n);
	printf("Average = %d\n", average);

	return 0;
}


int find_max(int ara[], int n) {
	int max = ara[0];
	int i;

	for (i = 1; i < n; i++) {
		if (ara[i] > max) {
			max = ara[i];
		}
	}

	return max;
}

int find_min(int ara[], int n) {
	int min = ara[0];
	int i;

	for (i = 1; i < n; i++) {
		if (ara[i] < min) {
			min = ara[i];
		}
	}
	return min;
}

int find_sum(int ara[], int n) {
	int sum = 0;
	int i;
	for (i = 0; i < n; i++) {
		sum += ara[i];
	}
	return sum;
}

int find_avrg(int ara[], int n) {
	int sum = 0, i;
	for (i = 0; i < n; i++) {
		sum += ara[i];
	}
	return (sum / n);
}