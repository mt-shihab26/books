#include <stdio.h>

int main(void)
{
    int ara[20], ara_2[20], i;
    for (i = 0; i < 20; i++) ara[i] = i+2;
    FILE *fp ;
    fp = fopen("write-array-with-fwrite_temp.bi", "wb");
    if (fp == NULL) {
        printf("Can't open the file\n");
        return 1;
    }

    fwrite(ara, sizeof(ara), 1, fp);

    fclose(fp);

    return 0;
}