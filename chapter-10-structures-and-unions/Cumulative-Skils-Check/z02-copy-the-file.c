// copy the file
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *from, *to;
    union u_type {
        int i;
        char ch;
    } uvar;

    // see if correct number of command line arguments
    if (argc != 3) {
        printf("Usage: copy <source> <destination>\n");
        exit(10);
    }

    // open source file
    if ((from = fopen(argv[1], "rb")) == NULL) {
        printf("Cannot open source file.\n");
        exit(1);
    }

    // open destination file
    if ((to = fopen(argv[2], "wb")) == NULL) {
        printf("Cannot open destination file\n");
        exit(1);
    }

    // copy the file
    for (;;) {
        uvar.i = fgetc(from);
        if (uvar.i == EOF) break;
        fputc(uvar.ch, to);
    }
    fclose(from);
    fclose(to);

    return 0;
}