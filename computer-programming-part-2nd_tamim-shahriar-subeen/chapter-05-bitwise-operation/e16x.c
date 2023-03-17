#include <stdio.h>

int main(void)
{
    int ara[] = {1, 2, 3, 4, 5, 8, 9, 10};
    int len = 10, i, inx, count = 0;

    for (i = 1, inx = 0; i <= len; i++, inx++) {
        if (ara[inx] ^ i) {
            printf("Missing number is %d\n", i);
            inx = i+1;
            count++;
        }
        if (count == 2)
            break;
    }

    return 0;
}