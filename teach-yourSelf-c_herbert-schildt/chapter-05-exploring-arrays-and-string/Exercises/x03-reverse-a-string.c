#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[80];
    int i;

    printf("Enter a stirng: ");
    gets(str);

    for (i = strlen(str) - 1; i >= 0; i--)
        printf("%c", str[i]);

    return 0;
}