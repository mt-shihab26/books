#include <stdio.h>

int main(void)
{
    char mess[80];
    int i;

    printf("Enter message (less than 80 character)\n");
    for (i = 0; i < 80; i++) {
        scanf("%c", &mess[i]);
        if (mess[i] == '\n') break;
    }
    mess[i] = '\0';

    printf("\n");

    for (i = 0; mess[i] != '\0'; i++) printf("%c", mess[i]);

    return 0;
}