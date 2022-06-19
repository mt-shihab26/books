#include <stdio.h>

int main(void)
{
    char str[100];

    fgets(str, 100, stdin);

    printf("%s", str);

    return 0;
}