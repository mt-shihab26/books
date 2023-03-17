#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char ch;
    int count, i;

    if ((fp = fopen("myfile", "r")) == NULL) {
        printf("Cannot open the file\n");
        exit(1);
    }
    count = 0;

    while((ch = fgetc(fp)) != EOF) {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            count++;
        }
    }
    fclose(fp);
    
    printf("Count: %d\n", count);

    return 0;
}