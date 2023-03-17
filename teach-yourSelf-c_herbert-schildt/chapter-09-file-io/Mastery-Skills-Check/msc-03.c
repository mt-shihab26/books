#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    FILE *fp;
    int num;

    if ((fp = fopen("RAND", "wb")) == NULL) {
        printf("Cannot open the file.\n");
        return 1;
    }

    int t = 100;

    while (t--)
    {
        num  = rand();
        fwrite(&num, sizeof num, 1, fp);
    }

    fclose(fp);

    return 0;
}