#include <stdio.h>
#include <string.h>

int main() {
	int t, area, len, i;
	int str[102];

	scanf("%d", &t);
	while (t--) {
		area = 1;
		for (i = 0; i < 3; i++){
			scanf("%d", &str[i]);
			area *=  str[i];
		}
		printf("%d\n", area);
	}

	return 0;
}
