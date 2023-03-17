#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    unsigned long long count = 0;

    // see if correct number fo command line arguments
    if (argc != 2) {
        printf("Useage: count <file>\n");
        return 1;
    }

    // open the file
    if ((fp = fopen(argv[1], "rb")) == NULL) {
        printf("Cannot open the file.\n");
        return 1;
    }

    // counting the bytes
    while (!feof(fp)) {
        fgetc(fp);
        if (ferror(fp)) {
            printf("File error.\n");
            return 1;
        }
        count++;
    }

    // closing the file
    if (fclose(fp) == EOF) {
        printf("Error closing the file.\n");
        return 1;
    }

    printf("The number of Bytes in the file: %llu\n", count-1);

    return 0;
}