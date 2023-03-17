#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    FILE *fp;

    if ((fp = fopen("fseek_temp", "w")) == NULL) {
        printf("Cannot open the file.\n");
        return EXIT_FAILURE;
    }

    fprintf(fp, "200");
    fseek(fp, 1, SEEK_SET);
    fprintf(fp, "199");

    return EXIT_SUCCESS;
}