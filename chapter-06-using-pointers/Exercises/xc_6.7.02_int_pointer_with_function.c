#include <stdio.h>

void int_pointer_fun(int *num) {
    *num = -1;
}

int main() {
    int num = 100;

    int_pointer_fun(&num);

    printf("%d\n", num);

    return 0;
}