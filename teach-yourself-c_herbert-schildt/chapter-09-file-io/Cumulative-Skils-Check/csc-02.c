#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fps, *fpd;
    char ch;

    if (argc != 3) {
        printf("Usage: copy <source> <destination>\n");
        return 1;
    }

    if ((fps = fopen(argv[1], "r")) == NULL) {
        printf("Cannot open the source file.\n");
        return 1;
    }

    if ((fpd = fopen(argv[2], "w")) == NULL) {
        printf("Cannot open the destination file.\n");
        return 1;
    }

    int count = 0, teb;
    while (!feof(fps))
    {
        fscanf(fps, "%c", &ch);
        if (ch == '\t') {
            for (teb = count; teb < count+4; teb++) {
                fputc(' ', fpd);
            }
        }
        else {
            fputc(ch, fpd);
        }
        count++;
    }
    fclose(fps);
    fclose(fpd);
    return 0;
}
