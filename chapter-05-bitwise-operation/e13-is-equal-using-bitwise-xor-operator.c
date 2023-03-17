#include <stdio.h>

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);

    if (n ^ m)
        printf("Numbers are not equal\n");
    else 
        printf("Numbers are equal\n");

    return 0;
}