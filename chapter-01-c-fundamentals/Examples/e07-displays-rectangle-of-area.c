#include <stdio.h>

int main(void)
{
    int len, width;

    printf("Enter a length: ");
    scanf("%d", &len);
    printf("Enter width: ");
    scanf("%d", &width);

    printf("Area is %d", len * width);

    return 0;
}