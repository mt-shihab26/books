#include <stdio.h> 
#include <math.h>
#include <string.h>

void array_sorting(int array[], int len) {
    int i, j, temp;
    for (i = 0; i < len; i++) {
        for (j = i+1; j < len; j++) {
            if (array[i] > array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        printf(" %d", array[i]);
    }
}

int main() {
    int num, i, j, k;

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
        int small_divisor[num];
        printf("Factors of %d : 1", num);
        for (i = 2, j = 0; i <= (sqrt(num))+1; i++) {
            if (num % i == 0) {
                small_divisor[j] = i;
                j++;
            }
        }
        for (k = j, i = 0; i < j; i++) {
            if (num / small_divisor[i] != small_divisor[i]) {
                small_divisor[k] = num / small_divisor[i];
                k++;
            }
        }
        array_sorting(small_divisor, k);
        // printf("\nk = %d\n", k);
        // for (i = 0; i < k; i++) {
        //     printf(" %d", small_divisor[i]);
        // }
        
        printf(" %d\n\n", num);
    }

    return 0;
}
