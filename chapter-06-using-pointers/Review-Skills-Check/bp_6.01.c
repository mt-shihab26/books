#include <stdio.h>

int main() {
    int array[10], i, even_sum = 0, odd_sum = 0;

    for (i = 0; i < 10; i++) {
        scanf("%d", &array[i]);
        if (array[i] % 2 == 0)
            even_sum += array[i];
        else
            odd_sum += array[i];
    }
    printf("Even number summation geven array is %d\n", even_sum);
    printf("Odd number summation geven array is %d\n", odd_sum);

    return 0;
}