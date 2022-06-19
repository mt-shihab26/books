#include <stdio.h>

int main(void)
{
    char ch;
    
    printf("Do you wish to continue? (Y/N): ");
    ch = getchar();
    if (ch == 'Y') {
        printf("Proceed\n");
    }
}