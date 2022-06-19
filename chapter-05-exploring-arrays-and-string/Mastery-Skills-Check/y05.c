#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[80];

    do {
        scanf("%s", str);
        printf("%s\n", str);
    } while (strcmp(str, "quit"));

    return 0;
}