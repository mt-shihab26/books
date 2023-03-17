#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *fp, *fpc;
    char str[81], c;
    int last;
    
    if (argc != 3){
        printf("Usage: a.out <sourse> <copy>\n");
        return 1;
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("Cannot open the file.\n");
        return 1;
    }
    if ((fpc = fopen(argv[2], "w")) == NULL) {
        printf("Cannot open the file2.\n");
        return 1;
    }

    while (!feof(fp)) {
        c = fgetc(fp);
        fputc(toupper(c), fpc);
    }

    fclose(fp);
    fclose(fpc);

    return 0;
}