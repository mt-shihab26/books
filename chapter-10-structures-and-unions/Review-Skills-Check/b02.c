#include <stdio.h>

int main(void)
{
    FILE *fp;

    if ( (fp = fopen("outfile_temp.txt", "w")) == NULL ) {
        printf("File opening faile\n");
        return 1;
    }

    fprintf(fp, "%s %lf %X %c\n", "this is a string", 1230.23, 0x1FFF, 'A');
    
    if (ferror(fp)) {
        printf("File writing faile\n");
        return 1;
    }

    return 0;
}