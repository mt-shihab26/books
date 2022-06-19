#include <stdio.h>

int main()
{
	int i = 0, t, n;
	
	scanf("%d", &t);
	while (i < t) {
		scanf("%d", &n);
		if (n % 2 == 0) {
			printf("even\n");
		}
		else {
			printf("odd\n");
		}
		i += 1;
	}
	return 0;
}
