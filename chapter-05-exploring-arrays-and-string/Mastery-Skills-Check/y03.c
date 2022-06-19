#include <stdio.h>

int main(void)
{
    int ara[20], i, j, count[20], main_count_indx = 0;
    
    for (i = 0; i < 20; i++) {
        printf("Enter element %d: ", i+1);
        scanf(" %d", &ara[i]);
        count[i] = 0;
    } 

    for (i = 0; i < 20; i++) {
        for (j = 0; j < 20; j++) {
            if (ara[i] == ara[j]) count[i]++;
        }
        if (count[main_count_indx] < count[i]) main_count_indx = i;
    }

    printf("The mode is %d\n", ara[main_count_indx]);

    return 0;
}