#include <stdio.h>

int main() {
    int t, n1, n2, n3, temp, i = 1;

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n1, &n2, &n3);
        temp = 0;
        if (n1 > n2) {
            temp = n1;
            n1 = n2;
            n2 = temp;
        }
        temp = 0;
        if (n1 > n3) {
            temp = n1;
            n1 = n3;
            n3 = temp;
        }
        temp = 0;
        if (n2 > n3) {
            temp = n2;
            n2 = n3;
            n3 = temp;
        }
        printf("Case %d: %d %d %d\n", i, n1, n2, n3);
		i++;
    }
    return 0;
}
