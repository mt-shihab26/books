#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char command[80], temp[80];
    int i, j;

    for ( ; ; ) {
        printf("Operation? ");
        gets(command);

        // see if user want top stop
        if (!strcmp(command, "quit")) break;

        printf("Enter first number: ");
        gets(temp);
        i = atoi(temp);

        printf("Enter second number: ");
        gets(temp);
        j = atoi(temp);

        // now , perform the operation
        if (!strcmp(command, "add")) printf("%d\n", i+j);
        else if (!strcmp(command, "subtract")) printf("%d\n", i-j);
        else if (!strcmp(command, "divide"))
            if (j) printf("%d\n", i/j);
        else if (!strcmp(command, "multiply")) printf("%d\n", i*j);
        else printf("Unknown command. \n");
    }

    return 0;
}