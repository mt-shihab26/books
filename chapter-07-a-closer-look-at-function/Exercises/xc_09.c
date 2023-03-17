#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Useage: a.out <number1> <number2>\nTry Again\n");
        exit(1);
    }

    printf("%s + %s = %d\n", argv[1], argv[2], atoi(argv[1]) + atoi(argv[2]));

    return 0;
}