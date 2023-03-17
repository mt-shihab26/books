#include <stdio.h>

int main(void)
{
    int num, i;

    printf("Enter the number to test: ");
    scanf("%d", &num);

    for (i=2; i<(num/2)+1; i=i+1)
        if ((num%i) == 0) printf("%d ", i);

    return 0;
}