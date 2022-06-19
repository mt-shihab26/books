#include <stdio.h>

int max(int marks[]) {
    int i;
    int maximum = marks[0];
    for (i = 1; i < 5; i++) {
        if (marks[i] > maximum) {
            maximum = marks[i];
        }
    }
    return maximum;
}

int min(int marks[]) {
    int i;
    int minimum = marks[0];
    for (i = 1; i < 5; i++) {
        if (marks[i] < minimum) {
            minimum = marks[i];
        }
    }
    return minimum;
}

int main() {
    int t, i;
    int marks[5];

    scanf("%d", &t);
    while (t--) {
        for (i = 0; i < 5; i++) {
            scanf(" %d", &marks[i]);
            // printf("%d", marks[i]);
        }
        printf("%d %d\n", max(marks), min(marks));
    }

    return 0;
}