#include <stdio.h>

int main(void)
{
    char ch;
    int digit, punc, letter;

    printf("Enter characters, q to stop.\n");
    digit = 0;
    punc = 0;
    letter = 0;

    do {
        scanf(" %c", &ch);
        switch (ch) {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '0':
                digit++;
                break;
            case '.':
            case ',':
            case '?':
            case '!':
            case ':':
            case ';':
                punc++;
                break;
            default:
                letter++;
        }
    } while (ch != 'q');

    printf("\nDigits: %d\n", digit);
    printf("Punctuation: %d\n", punc);
    printf("Letters: %d\n", letter);

    return 0;
}