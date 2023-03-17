#include <stdio.h>

int main(void)
{
    char ch;

    while(1) {
        printf("Enter a char or 'q' to exit: ");
        scanf(" %c", &ch);

        if (ch == 'q') {
            break;
        }
        if (ch >= 'a' && ch <= 'z') {
            ch -= 32;
        }

        printf("%c\n", ch);
    }

    return 0;
}