#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *in, *out;
    unsigned char ch;

    if (argc != 3)
    {
        printf("Usage: code <in> <out>\n");
        return 1;
    }

    if ((in = fopen(argv[1], "rb")) == NULL)
    {
        printf("Cannot open input file.\n");
        return 1;
    }

    if ((out = fopen(argv[2], "wb")) == NULL)
    {
        printf("Cannot open output file.\n");
        return 1;
    }

    while (!feof(in))
    {
        ch = fgetc(in);
        if (!feof(in))
            fputc(~ch, out);
    }

    fclose(in);
    fclose(out);

    return 0;
}