#include <stdio.h>
#include <math.h>

int is_prime(int num) {
    int root = sqrt(num);
    int i;
    if (num < 2) {
        return 0;
    }
    if (num == 2 || num == 3) {
        return 1;
    }
    if (num % 2 == 0) {
        return 0;
    }
    for (i = 3; i <= root; i += 2) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int t, counts, i;
    int marks[10];

    scanf("%d", &t);
    while (t--) {
        counts = 0;
        for (i = 0; i < 10; i++) {
            scanf("%d", &marks[i]);
            if (1 == is_prime(marks[i])) {
                counts += 1;
            }
        }
        printf("%d\n", counts);
    }

    return 0;
}