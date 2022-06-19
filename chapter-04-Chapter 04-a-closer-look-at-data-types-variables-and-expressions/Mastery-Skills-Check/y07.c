#include <stdio.h>

int series(void);

int num = 21;

int main(void)
{
    int i;

    for (i = 0; i < 10; i++) {
        printf("%d ", series());
    }
    return 0;
}

int series(void)
{
    num = (num * 1468) % 467;
    return num;
}