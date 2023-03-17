#include <stdio.h> 

int main() {
    int num, i;

    while(1) {
        printf("Please enter a positive integer. Enter 0 to quit\n: ");
        scanf("%d", &num);
        if (num == 0) {
            break;
        }
        if (num < 0) {
            printf("You must enter a positive integer. Please try again.\n");
            continue;
        }
        printf("Factors of %d : 1", num);
        for (i = 2; i <= (num/2)+1; i++) {
            if (num % i == 0) {
                printf(" %d", i);
            }
        }
        printf(" %d\n\n", num);
    }

    return 0;
}