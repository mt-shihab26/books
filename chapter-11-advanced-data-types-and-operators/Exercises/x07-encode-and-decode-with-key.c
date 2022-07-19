#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *in, *out;
    if (argc != 4)
    {
        printf("Usage: code <in> <out> <key>");
        return 0;
    }

    if ((in = fopen(argv[1], "r")) == NULL)
    {
        printf("Cannot open input file.\n");
        return 1;
    }

    if ((out = fopen(argv[2], "w")) == NULL)
    {
        printf("Cannot open output file.\n");
        return 1;
    }

    char key = argv[3][0], c;

    while (!feof(in))
    {
        fscanf(in, "%c", &c);
        fprintf(out, "%c", c ^ key);
    }

    fclose(in);
    fclose(out);
    return 0;
}
