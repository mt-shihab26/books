#include <stdio.h>

struct s_type {
    int i;
    char ch;
    int *p;
    double d;
} s;

int main(void)
{
    // printf("%ld", sizeof(s.p));
    printf("s_type is %ld bytes long\n", sizeof(struct s_type));

    return 0;
}