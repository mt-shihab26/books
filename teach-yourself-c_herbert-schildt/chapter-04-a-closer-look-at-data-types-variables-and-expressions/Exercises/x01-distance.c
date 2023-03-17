#include <stdio.h>

int main(void)
{
    unsigned long int distance;

    printf("Enter the Distance: ");
    scanf("%lu", &distance);

    printf("%lu second\n", distance/186000);

    return 0;
}