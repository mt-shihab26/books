#include <stdio.h>

int main(void)
{
    char f[101];

    scanf("%[0-9.]", f);
    printf("%s\n", f);

    return 0;
}