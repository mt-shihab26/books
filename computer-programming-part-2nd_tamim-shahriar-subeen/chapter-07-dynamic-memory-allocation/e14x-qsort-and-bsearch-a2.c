#include <stdio.h>
#include <stdlib.h>

int comparefunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(void)
{
    int values[] = {1, 6, 34, 345, 3, 45, 8, 9, 23, 34}, len = 10;
    int key, *item;

    qsort(values, len, sizeof(int), comparefunc);

    while (1) {
        printf("Enter the key (0 to exit): ");
        scanf("%d", &key);
        if (key == 0) break;
        item = (int *) bsearch(&key, values, len, sizeof(int), comparefunc);

        if (item == 0)
            printf("Item was not found\n");
        else
            printf("Item Found\n");
    }

    return 0;

}