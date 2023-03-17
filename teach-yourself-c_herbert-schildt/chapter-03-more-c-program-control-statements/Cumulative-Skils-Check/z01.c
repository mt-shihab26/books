#include <stdio.h>

int main(void)
{
    char ch;

    do {
        printf("Enter a char or q to quit: ");
        scanf(" %c", &ch);

        switch (ch) {
        case '\n': 
            printf("Newline\n");
            break;
        case '\t':
            printf("tab\n");
            break;
        case '\b':
            printf("backspaces\n");
            break;
        }
    } while (ch != 'q');

    return 0;
}