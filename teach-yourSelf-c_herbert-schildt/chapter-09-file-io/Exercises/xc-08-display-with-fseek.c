#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //check command line argument
    if (argc != 2) {
        printf("Usage: <file>\n");
        return 1;
    }

    FILE *fp;

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        printf("Cannot open the file.\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long end = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    for (int i = 0; i < end; i++) {
        fseek(fp, i, SEEK_SET);
        printf("%c", fgetc(fp));
    }
    printf("\n");
    return 0;
}