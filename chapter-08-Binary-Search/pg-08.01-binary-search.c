#include <stdio.h>

int binary_search(int ara[], int number) {
    int i, low_indx = 0, heigh_indx = 15;
    int mid_indx;
    while (low_indx <= heigh_indx) {
        mid_indx = (heigh_indx + low_indx) / 2;
        if (number == ara[mid_indx]) {
            break;
        }
        else if (ara[mid_indx] < number) {
            low_indx = mid_indx + 1;
        }
        else {
            heigh_indx = mid_indx - 1;
        }
    }
    if (low_indx > heigh_indx) {
        printf("-> %d is not in the array\n", number);
    }
    else {
        printf("-> %d is found in the array. It is the %d th element of the array.\n", ara[mid_indx], mid_indx);

    }
    return 0;
}

int main() {
    int ara[16] = {1, 4, 6, 8, 9, 11, 14, 15, 20, 25, 33, 83, 87, 97, 99, 100};
    int num, i;
    printf("Enter the number from:-\n");
    for (i = 0; i < 16; i++){
        printf("%d ", ara[i]);
    }
    printf("\n\n");
    while(1) {
        printf("\nNow(quit to 0): ");
        scanf(" %d", &num);
        if (num == 0) {
            break;
        }
        int result = binary_search(ara, num);
    }
    return 0;
}