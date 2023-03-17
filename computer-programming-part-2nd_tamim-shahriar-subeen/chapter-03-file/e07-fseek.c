#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp = fopen("in.txt", "r");
    if (fp == NULL) {
        printf("Can't open file");
        return EXIT_FAILURE;
    }

    int ch;

    ch = fgetc(fp);
    printf("%c\n", (char)ch);
    ch = fgetc(fp);
    printf("%c\n", (char)ch);

    fseek(fp, sizeof(char)*4, SEEK_CUR);
    ch = fgetc(fp);
    printf("%c\n", (char)ch);

    fclose(fp);

    return 0;
}