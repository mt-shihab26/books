#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Useage: a.out <option> <number1> <number2>\nTry Again\n");
        exit(1);
    }
    int num1 = atoi(argv[2]), num2 = atoi(argv[3]);
    if (strcmp(argv[1], "add") == 0) {
        printf("%d + %d = %d\n", num1, num2, num1 + num2);
        exit(0);
    }
    if (strcmp(argv[1], "subtract") == 0) {
        printf("%d - %d = %d\n", num1, num2, num1 - num2);
        exit(0);
    }
    if (strcmp(argv[1], "multiply") == 0) {
        printf("%d x %d = %d\n", num1, num2, num1 * num2);
        exit(0);
    }
    if (strcmp(argv[1], "divide") == 0) {
        printf("%d / %d = %d\n", num1, num2, num1 / num2);
        exit(0);
    }

    return 0;
}