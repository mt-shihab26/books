#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    return *(char *)a - *(char *)b;
}

int main()
{
    char str[] = "this is a test of qsort";
    int len = strlen(str);

    qsort(str, len, 1, cmp);

    printf("%s\n", str);

    return 0;
}