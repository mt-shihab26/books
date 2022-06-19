#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    FILE *fp;

    unsigned char ch, val;

    // check command line
    if (argc != 3) {
        printf("Usage: <file> <intValue>\n");
        return 1;
    }

    //open the file
    if ((fp = fopen(argv[1], "rb")) == NULL) {
        printf("Cannot open the file.\n");
        return 1;
    }

    val = atoi(argv[2]);

    while (!feof(fp)) {
        ch = fgetc(fp);
        if (ch == val)
            printf("Found value at %ld\n", ftell(fp));
    }
    fclose(fp);

    return 0;
}