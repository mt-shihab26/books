#include <stdio.h>

int main(void)
{
    char str[80];
    int i;

    printf("Enter a string (less than 80 chars): ");
    gets(str);
    for (i = 0; str[i]; i++) printf("%c", str[i]);
}