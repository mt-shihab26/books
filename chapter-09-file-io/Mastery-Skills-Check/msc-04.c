#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    FILE *fp;
    int num;

    if ((fp = fopen("RAND", "rb")) == NULL) {
        printf("Cannot open the file.\n");
        return 1;
    }

    int t = 100;

    while (t--)
    {
        fread(&num, sizeof num, 1, fp);
        printf("%d\n", num);
    }

    fclose(fp);

    return 0;
}