#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    long loc;
    FILE *in, *out;

    char ch;

    // see if correct number of command line arguments
    if (argc != 3) {
        printf("Usage: revcopy <sourcs> <destination>.\n");
        return EXIT_FAILURE;
    }

    if ((in = fopen(argv[1], "rb")) == NULL) {
        printf("Cannot open input file.\n");
        return EXIT_FAILURE;
    }
    if ((out = fopen(argv[2], "wb")) == NULL) {
        printf("Cannot open output file.\n");
        return EXIT_FAILURE;
    }

    // find end of source file
    fseek(in, 0L, SEEK_END);
    loc = ftell(in);

    // copy file  in reverse order
    loc = loc-1; // back up past end of-file mark
    while(loc >= 0L) {
        fseek(in, loc, SEEK_SET);
        ch = fgetc(in);
        fputc(ch, out);
        loc--;
    }
    fclose(in);
    fclose(out);
}