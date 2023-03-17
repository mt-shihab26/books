#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char ch;

    fp = fopen("myfile", "r");

    while (!feof(fp)) {
        ch = fgetc(fp);
        if (ferror(fp)) {
            printf("File Error\n");
            break;
        }
    }

    return 0;
}