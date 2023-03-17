#include <stdio.h>
#include <stdlib.h>

#define error_cp printf("Cannot open file.\n")

double d[10] = {
    10.23, 19.87, 1002.23, 12.9, 0.897,
    11.45, 75.34, 0.0, 1.01, 875.875
};

int main(void) 
{
    int i;
    FILE *fp;
    
    if (( fp = fopen("myfile", "wb")) == NULL) {
        error_cp;
        exit(1);
    }

    //write the entire array in one step
    if (fwrite(d, sizeof d, 1, fp) != 1) {
        printf("Write error.\n");
        exit(1);
    }
    fcloingem(fp, "myfile", "wb");

    if ((fp = fopen("myfile", "rb")) == NULL) {
        error_cp;
        exit(1);
    }

    // clear the array
    for (i=0; i<10; i++)
        d[i] = -1.0;

    // read the entire array in one step
    if (fread(d, sizeof d, 1, fp) != 1) {
        printf("Read error.\n");
        exit(1);
    }

    fclose(fp);

    // display the array
    for (i=0; i<10; i++) 
        printf("%lf", d[i]);

    return 0;
}