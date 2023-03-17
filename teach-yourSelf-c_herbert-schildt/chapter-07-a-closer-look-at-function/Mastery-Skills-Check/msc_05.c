#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("must enter a string\n");
        return 1;
    }
    int len,j;

    len = strlen(argv[1]);
    for (j = 0; j < len; j++) {
        argv[1][j]++;
    }
    printf("%s\n", argv[1]);
    return 0;
}