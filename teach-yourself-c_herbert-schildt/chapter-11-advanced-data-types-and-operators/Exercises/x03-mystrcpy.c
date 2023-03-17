#include <stdio.h>
#include <string.h>

char *mystrcpy(char *to, const char *from);

int main(void)
{
    char to[200];
    char from[] = "shihab mahamud";
    mystrcpy(to, from);
    printf("%s", to);
}

char *mystrcpy(char *to, const char *from)
{
    while (*from)
        *to++ = *from++;
    *to = '\0'; // NULL terminator
    return to;
}
