#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmp(const void *a, const void *b)
{
    int real_a = *(int *)a;
    int real_b = *(int *)b;

    return real_a - real_b;
}

int main(void)
{
    int a[100], i;

    srand(time(NULL));
    for (i = 0; i < 100; i++)
        a[i] = rand() % 200;

    qsort(a, 100, sizeof(int), cmp);

    for (i = 0; i < 100; i++)
        printf("%d ", a[i]);
    printf("\n");

    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int *item = (int *)bsearch(&num, a, 100, sizeof(int), cmp);
    if (item == NULL)
    {
        printf("not found");
        return 0;
    }
    printf("Item found at %ld\n", item - a);

    return 0;
}