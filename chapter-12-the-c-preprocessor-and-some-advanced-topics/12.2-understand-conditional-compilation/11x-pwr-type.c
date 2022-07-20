#include <stdio.h>

#define INT 0
#define FLOAT 1
#define PWR_TYPE FLOAT

int main(void)
{
#if PWR_TYPE == FLOAT
    double a;
    int b;
    printf("Enter double number in first and integer in second: ");
    scanf("%lf %d", &a, &b);
    printf("%lf %d\n", a, b);
#elif PWR_TYPE INT
    int a, b;
    printf("Enter two integers number: ");
    scanf("%d %d", &a, &b);
    printf("%d %d\n", a, b);
#endif
}