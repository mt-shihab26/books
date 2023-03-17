#include <stdio.h>
#include <string.h>

/*
Copy using redirection
Execute like this:

$ NAME < in > out
*/

int main(void)
{
    char ch;
    
    while (!feof(stdin)) {
        scanf("%c", &ch);
        if (!feof(stdin))
            printf("%c", ch);
    }
    return 0;
}