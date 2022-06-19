#include <stdio.h>

int main(void)
{
    int ara[] = {1, 2, 3, 4, 5, 7, 8, 9, 10};
    int len = 10, i;

    for (i = 1; i <= len; i++) {
        if (ara[i-1] ^ i) {
            printf("Missing number is %d\n", i);
            break;
        }
    }

    return 0;
}