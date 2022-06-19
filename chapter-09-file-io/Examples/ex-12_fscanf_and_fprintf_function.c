#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    double ld;
    int d;
    char str[80];

    // ckeck for command line arg
    if (argc != 2) {
        printf("Specifiy file name.\n");
        exit(1);
    }

    // open file for input
    if ((fp = fopen(argv[1], "w")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }

    fprintf(fp, "%f %d %s", 12345.342, 1908, "hello");
    if (fclose(fp) == EOF) {
        printf("Cannot closed the file.\n");
        exit(1);
    }

    // open file for output
    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }

    fscanf(fp, "%lf%d%s", &ld, &d, str);
    printf("%lf %d %s\n", ld, d, str);
    if (fclose(fp) == EOF) {
        printf("Cannot closed the file.\n");
        exit(1);
    }

    return 0;
}