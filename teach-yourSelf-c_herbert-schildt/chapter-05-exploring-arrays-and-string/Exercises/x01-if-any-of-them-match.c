#include <stdio.h>

int main(void)
{
    int i, ara[10], j;

    for (i = 0; i < 10; i++) scanf("%d", &ara[i]);
    printf("\n");
    for (i = 0; i < 10; i++)
        for (j = i+1; j < 10; j++)
            if (ara[i] == ara[j]) printf("%d\n", ara[i]);

    return 0;
}