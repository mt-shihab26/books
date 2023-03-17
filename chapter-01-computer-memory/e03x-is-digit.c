#include <stdio.h>

char is_digit(char ch);

int main(void)
{
    char ch;
    printf("Enter a char: ");
    ch = getchar();
    if (is_digit(ch))
        printf("%c is A digit\n", ch);
    else 
        printf("%c is Not A digit\n", ch);
}

char is_digit(char ch)
{
    if (ch >= '0' && ch <= '9')
        return 1;
    return 0;
}