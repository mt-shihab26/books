#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Useage: copy <sourcefile> <copiedFile> <opetion>\n");
        return 1;
    }
    
    FILE *fp, *fpo;
    char ch;

    // open the source file
    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("Can't Read file\n");
        return 1;
    }
    if ((fpo = fopen(argv[2], "w")) == NULL) {
        printf("Can't Open file\n");
        return 1;
    }

    int is = 0;
    if (!(strcmp(argv[3], "watch")))
        is = 1;

    while ((ch = fgetc(fp)) != EOF) {
        if (is)
            putchar(ch);
        fputc(ch, fpo);
        // *fpo++;
    }
    fclose(fp);
    fclose(fpo);
    

    return 0;
}