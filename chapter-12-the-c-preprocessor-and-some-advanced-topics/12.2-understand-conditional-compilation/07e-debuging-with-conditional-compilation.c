/* copy a file */
#include <stdio.h>
#include <stdlib.h>

#define DEBUG

int main(int argc, char **argv)
{
    FILE *from, *to;
    char ch;

    /* see if correct number of command line arguments */
    if (argc != 3)
    {
        printf("Usage: copy <source> <destination>\n");
        exit(10);
    }

    // open source file
    if ((from = fopen(argv[1], "rb")) == NULL)
    {
        printf("Cannot open source file.\n");
        exit(1);
    }

    // open destination file
    if ((to = fopen(argv[2], "wb")) == NULL)
    {
        printf("Cannot open destination file\n");
        exit(1);
    }

    /* copy the file */
    while (!feof(from))
    {
        ch = fgetc(from);
        if (ferror(from))
        {
            printf("Error reading source file\n");
            exit(1);
        }
        if (!feof(from))
        {
            fputc(ch, to);
#ifdef DEBUG
            putchar(ch);
#endif
        }
        if (ferror(to))
        {
            printf("Error writing destination file.\n");
            exit(1);
        }
    }

    fclose(from);
    fclose(to);
}