#include <stdio.h>

int main(void)
{
    int num;
    float f;

    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("Entar a floating point number: ");
    scanf(" %f", &f);

    printf("%d ", num);
    printf("%lf", f);

    return 0;
}