#include <stdio.h>

int main() {
    int count = 0, i;
    int *count_p = NULL;

    for (i = 0; i <= 9; i++) {
        count += i;
    }

    count_p = &count;

    printf("%d %d\n",count, *count_p);

    return 0;
}