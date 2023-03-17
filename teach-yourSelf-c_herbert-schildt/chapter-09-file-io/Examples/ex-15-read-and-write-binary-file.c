#include <stdio.h>
#include <stdlib.h>
// #include "../mine.h"

double d[10] = {
    10.23, 19.87, 1002.23, 12.9, 0.897,
    11.45, 75.34, 0.0, 1.01, 875.875
};

int main(void)
{
    int i;
    FILE *fp;

    if ((fp = fopen("myfile_temp.txt", "wb")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }

    for (i=0; i<10; i++) {
        if (fwrite(&d[i], sizeof(double), 1, fp) != 1) {
            printf("Write error.\n");
            exit(1);
        }
    }
    fclose(fp);

    if ((fp = fopen("myfile_temp.txt", "rb")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }

    // clear the array
    for (i=0; i<10; i++) d[i] = -1.0;

    for (i=0; i<10; i++) {
        if (fread(&d[i], sizeof(double), 1, fp) != 1) {
            printf("Read error.\n");
            exit(1);
        }
    }
    fclose(fp);

    //display the array
    for (i=0; i<10; i++) printf("%lf\n", d[i]);

    return 0;
}