#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Please enter two string\n");
    }
    int i = strcmp(argv[1], argv[2]);
    if (i < 0)
        printf("%s < %s\n", argv[1], argv[2]);
    else if (i > 0)
        printf("%s > %s\n", argv[1], argv[2]);
    else
        printf("They are same\n");
}