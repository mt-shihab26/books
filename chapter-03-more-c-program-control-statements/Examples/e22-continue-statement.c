#include <stdio.h>

int main(void)
{
    int x;

    for (x = 0; x < 100; x++) {
        printf("ok %d\n", x);
        continue;

        printf("%d ", x); // this is never executed
    }
}