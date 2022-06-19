#include <stdio.h>

int main(void)
{
    int i;

    for (i = 0; i < 10; i++) {
        if (i == 5) {
            int j; // declare j within the if block
            
            j = i * 10;
            printf("%d", j);
        }
    }

    return 0;
}