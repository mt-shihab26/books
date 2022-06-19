#include <stdio.h>

int main(void)
{
    char ch;

    printf("Enter the letter: ");
    scanf(" %c", &ch);

    switch (ch)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'y':
        printf(" is a vowel\n");
        break;
    default:
        printf(" is a consonant\n");
    }

    return 0;
}