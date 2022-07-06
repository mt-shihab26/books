#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *in, *out;
    if (argc != 4)
    {
        printf("Usage: code <in> <out> <key>");
        return 0;
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
}