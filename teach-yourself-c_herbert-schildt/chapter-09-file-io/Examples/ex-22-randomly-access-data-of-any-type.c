#include <stdlib.h>
#include <stdio.h>

double d[10] = {
    10.23, 19.87, 1002.23, 12.9, 0.897,
    11.45, 75.34, 0.0, 1.01, 875.875
};

int main(void)
{
    long loc;
    double value;
    FILE *fp;

    if ((fp = fopen("myfile", "wb")) == NULL) {
        printf("Cannot open file.\n");
        return EXIT_FAILURE;
    }

    // write the entire array in one step
    if (fwrite(d, sizeof d, 1, fp) != 1) {
        printf("Write error.\n");
        return EXIT_FAILURE;
    }
    fclose(fp);

    if ((fp = fopen("myfile", "rb")) == NULL) {
        printf("Cannot open file.\n");
        return EXIT_FAILURE;
    }

    printf("Which element? ");
    scanf("%ld", &loc);
    if (fseek(fp, loc*sizeof(double), SEEK_SET)) {
        printf("Seek error.\n");
        return EXIT_FAILURE;
    }

    fread(&value, sizeof(double), 1, fp);
    printf("Element %ld is %f", loc, value);
    
    fclose(fp);

    return 0;
}