#include <stdio.h>

int main() {
    double marks[4][10] =  {{80, 70, 92, 78, 58, 83, 85, 66, 99, 81}, {75, 67, 55, 100, 91, 84, 79, 61, 90, 97}, {98, 67, 75, 89, 81, 83, 80, 90, 88, 77}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    int j;

    for (j = 0; j < 10; j++) {
        marks[3][j] = (marks[0][j] / 4.0) + (marks[1][j] / 4.0) + (marks[2][j] / 2.0);
        printf("Roll = %d\tTotal Marks = %.2lf\n", j+1, marks[3][j]);
    }
}