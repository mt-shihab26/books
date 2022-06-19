#include <stdio.h>

struct test {
    int a: 5;
    int b: 3;
    int c: 3;
};

typedef struct test test_type;

int main(void)
{
    test_type test_var;
    test_var.a = 5;
    test_var.b = 0;
    test_var.c = 3;

    printf("%d %d %d", test_var.a, test_var.b, test_var.c);

    return 0;
}