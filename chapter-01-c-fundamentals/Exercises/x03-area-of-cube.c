#include <stdio.h>

int main(void)
{
    int dimention;

    printf("Enter Cube dimention: ");
    scanf("%d", &dimention);

    printf("The area of cube is %d", dimention*dimention*dimention);

    return 0;
}