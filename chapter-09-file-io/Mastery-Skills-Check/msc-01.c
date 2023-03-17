#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    char str[81];
    int last;
    
    if (argc != 2){
        printf("Usage: a.out <filename>\n");
        return 1;
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("Cannot open the file.\n");
        return 1;
    }

    while (!feof(fp)) {
        fgets(str, 80, fp);
        last = strlen(str) - 1;
        str[last] = '\0';
        if (!feof(fp))
            printf("%s", str);
        printf("...More? (y/n) ");
        if (toupper(getchar()) == 'N')
            break;
    }
    fclose(fp);

    return 0;
}