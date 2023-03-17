#include <stdio.h>

int main(void)
{
    FILE *fp;
    int ara_2[20], i;

    fp = fopen("write-array-with-fwrite_temp.bi", "rb");
    if (fp == NULL) {
        printf("Can't open the file\n");
        return 1;
    }
    fread(ara_2, sizeof(ara_2), 1, fp);
    fclose(fp);

    for (i = 0; i < 20; i++) {
        printf("%d\n", ara_2[i]);
    }
    return 0;
}