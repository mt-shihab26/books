#include <stdio.h>

int main(void)
{
    int i;
    char ch, smallest;

    printf("Enter 10 letters.\n");

    smallest = 'z'; // make largest to bigin with

    for (i = 0; i<10; i++) {
        // ch = getche();
        // ch = getchar();
        if (ch < smallest) smallest = ch;
    }

    printf("\nThe smallest charcter is %c.", smallest);

    return 0;
}