#include <stdio.h>

struct num_type {
    int i;
    int sqr;
    int cube;
} nums[10];

int main(void) {
    int i;
    for (i=1; i<11; i++) {
        nums[i-1].i = i;
        nums[i-1].sqr = i*i;
        nums[i-1].cube = i*i*i;
    }

    for (i=0; i<10; i++) {
        printf("%d ", nums[i].i);
        printf("%d ", nums[i].sqr);
        printf("%d\n", nums[i].cube);
    }

    return 0;
}