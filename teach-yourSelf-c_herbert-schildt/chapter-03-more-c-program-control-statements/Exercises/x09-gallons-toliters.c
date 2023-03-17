#include <stdio.h>

int main(void)
{
    int gallons;

    printf("Enter gallons: ");
    scanf("%d", &gallons);

    do {
        printf("Liters: %f\n", gallons*3.7854);
        printf("Enter gallons(Enter 0 to exit): ");
        scanf("%d", &gallons);
    } while (gallons != 0);

    return 0;
}