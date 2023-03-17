#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *p = malloc(80);

    if (!p)
    {
        printf("Allocation Failed");
        return 1;
    }

    printf("Enter a string: ");
    gets(p);
    printf(p);
    free(p);
}