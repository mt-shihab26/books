#include <stdio.h>

int main(void)
{
    float feet, meters, ounces, pounds;
    int choiced;

    do {
        printf("Convert\n 1. feet to meters\n 2. meters to feet\n 3. ounces to pounds\n 4. pounds to ounces\n 5. Quit\n");
        do {
            printf("Enter the number of your choice: ");

            scanf(" %d", &choiced);

        } while (choiced < 1 || choiced > 5);

        switch (choiced) {
        case 1:
            printf("Enter feet: ");
            scanf("%f", &feet);
            printf("Meters: %f\n", feet / 3.28);
            break;
        case 2:
            printf("Enter meters: ");
            scanf("%f", &meters);
            printf("Feet: %f\n", feet * 3.28);
            break;
        case 3:
            printf("Enter ounces: ");
            scanf("%f", &ounces);
            printf("Pounds: %f\n", ounces / 16);
            break;
        case 4:
            printf("Enter pounds: ");
            scanf("%f", &pounds);
            printf("Ounces: %f\n", pounds * 16);
            break;
        }

    } while (choiced != 5);

    return 0;
}