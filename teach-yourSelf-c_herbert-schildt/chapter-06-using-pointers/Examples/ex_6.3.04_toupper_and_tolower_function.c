#include <stdio.h>
#include <ctype.h>

int main() {
    char str[80];
    int i;

    printf("Enter a string: ");
    gets(str);

    for (i = 0; str[i]; i++)
        str[i] = toupper(str[i]);

    printf("%s\n", str); // Uppercase string

    for (i = 0; str[i]; i++)
        str[i] = tolower(str[i]);

    printf("%s\n", str); // Lowercase string

    return 0;
}