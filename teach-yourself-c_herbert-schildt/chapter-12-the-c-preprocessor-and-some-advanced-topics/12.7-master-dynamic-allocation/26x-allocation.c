#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr = malloc(10 * sizeof(int));

    for (int i = 1; i <= 10; i++)
    {
        *(arr + i - 1) = i;
    }

    for (int i = 1; i <= 10; i++)
    {
        printf("%d ", arr[i - 1]);
    }
    printf("\n");

    free(arr);

    return 0;
}