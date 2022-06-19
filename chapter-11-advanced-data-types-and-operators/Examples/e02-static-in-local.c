#include <stdio.h>

void ok(int c);

int main(void) {
    ok(1);
    ok(1);
    return 0;
}

void ok(int c) {
    static int a = 1;
    a++;
    printf("%d\n", a);
}