#include <stdio.h>
#include <stdlib.h>

/*
DEBUG levels:
    0: no debug
    1: display byte read from source file
    2: display byte written to destination file
    3: display bytes read and bytes written
*/

#define DEBUG 2

int main(int argc, char **argv)
{
    FILE *in, *out;
    unsigned char ch;

    /* see if correct number of command line arguments */
    if (argc != 4)
    {
        printf("Usage: code <in> <out> <key>");
        return 1;
    }

    /* open input file */
    if ((in = fopen(argv[1], "r")) == NULL)
    {
        printf("Cannot open input file.\n");
        return 1;
    }

    /* open output file */
    if ((out = fopen(argv[2], "w")) == NULL)
    {
        printf("Cannot open output file.\n");
        return 1;
    }

    char key = argv[3][0], c;

    while (!feof(in))
    {
        fscanf(in, "%c", &c);
#if DEBUG == 1 || DEBUG == 3
        putchar(c);
#endif
        c ^= key;
#if DEBUG >= 2
        putchar(c);
#endif
        if (!feof(in))
            fprintf(out, "%c", c);
    }

    fclose(in);
    fclose(out);
    return 0;
}