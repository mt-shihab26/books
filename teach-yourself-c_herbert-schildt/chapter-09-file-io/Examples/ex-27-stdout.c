#include <stdio.h>

int main(void)
{
    fprintf(stdout, "%d %c %s\n", 100, 'c', "this is a string");
    printf("%d %c %s\n", 100, 'c', "this is a string");
    return 0;
}