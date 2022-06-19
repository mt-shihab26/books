#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    FILE *fp;
    long num;
    int i;

    if ((fp = fopen("RAND", "rb")) == NULL) {
        printf("Cannot open the file.\n");
        return 1;
    }

    printf("Which num (0-99)? ");
    scanf("%ld", &num);
    fseek(fp, num*sizeof(int), SEEK_SET);
    fread(&i, sizeof num, 1, fp);
    printf("%d\n", i);

    fclose(fp);

    return 0;
}