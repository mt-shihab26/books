#include <stdio.h>

int main(void)
{
    int num;
    printf("Enter your number: ");
    scanf("%d", &num);

    if (num > 0 && (num & (num-1)) == 0)
        printf("%d is power of 2\n", num);
    else 
        printf("%d is Not power of 2\n", num);
    
    return 0;
}