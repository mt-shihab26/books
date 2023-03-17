#include <stdio.h>
#define DEBUG 1

int add(int a, int b)
{
    return a + b;
}

int main(void)
{
    int lenght, i, sum = 0, tmp;

    printf("Enter Number of integers: ");
    scanf("%d", &lenght);
    if (DEBUG) printf("---\nDEBUG\n\tNumber of integers:%d\nENDDEBUG\n---\n", lenght);
    for (i = 0; i < lenght; i++) {
        printf("Enter Number %d: ", i+1);
        scanf("%d", &tmp);
        if (DEBUG) printf("---\nDEBUG\n\tNumber %d: %d\nENDDEBUG\n---\n");
        sum = add(sum, tmp);
        if (DEBUG) printf("---\nDEBUG‌\n\tCurrent Sum: %d\nENDDEBUG\n---\n", sum);
    }

    printf("The average is %lf\n", (double)sum / lenght);

    return 0;
}