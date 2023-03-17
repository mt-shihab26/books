#include <stdio.h>

int main(void)
{
    int room_number, i, temp, total_square = 0;

    printf("Enter Room Numbers: ");
    scanf("%d", &room_number);

    for (i=1; i<=room_number; i++) {
        printf("Enter dimensions for room %d: ", i);
        scanf("%d", &temp);
        total_square += temp*temp;
    }

    printf("Total Square: %d", total_square);

    return 0;
}