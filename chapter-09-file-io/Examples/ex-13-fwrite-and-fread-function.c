#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    int i, j;
    
    // open file for output
    if ((fp = fopen("myfile", "wb")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }

    i = 100;

    if (fwrite(&i, 4, 1, fp) != 1) {
        printf("Write error accourred.\n");
        exit(1);
    }
    fclose(fp);

    // open file for input
    if ((fp = fopen("myfile", "rb")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }

    if (fread(&j, 4, 1, fp) != 1) {
        printf("Read error accurred.\n");
        exit(1);
    }

    printf("i is %d", j);
    fclose(fp);
    return 0;
}