#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    char fname[80];

    printf("Enter name of file to erase: ");
    gets(fname);
    printf("Are you sure? (Y/N) ");
    if (toupper(getchar()) == 'Y')
        if (remove(fname))
            printf("Error: tries to remove a nonexistent file.\n");
    
    return 0;
}