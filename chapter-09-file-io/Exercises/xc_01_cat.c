#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char ch;

    if(argc != 2) {
        printf("Useage: cat <filename>\n");
        exit(1);
    }

    // open the file
    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("Cannot open the file\n");
        exit(1);
    }

    // Output show
    while ((ch = fgetc(fp)) != EOF) putchar(ch);
    fclose(fp);

    return 0;
}