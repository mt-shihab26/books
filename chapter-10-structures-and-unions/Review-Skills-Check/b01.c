#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) 
{
    if (argc != 3) {
        printf("Useage: copy <source> <distination>\n");
        return 1;
    }

    FILE *fp_s, *fp_d;

    if ( (fp_s = fopen(argv[1], "rb")) == NULL ) {
        printf("File opening faile: soruce\n");
        return 1;
    }
    if ( (fp_d = fopen(argv[2], "wb")) == NULL ) {
        printf("File opening faile: distination\n");
        return 1;
    }
    
    char c;

    while (!feof(fp_s)) {
        c = fgetc(fp_s);
        if (ferror(fp_s)) {
            printf("File reading faile: soruce\n");
            return 1;
        }
        fputc(c, fp_d);
        if (ferror(fp_d)) {
            printf("File writing faile: distination\n");
            return 1;
        }
    }

    if (fclose(fp_s) == EOF) {
        printf("Faile closeing soruce file\n");
        return 0;
    }

    if (fclose(fp_d) == EOF) {
        printf("Faile closeing distination file\n");
        return 0;
    }

    return 0;
}