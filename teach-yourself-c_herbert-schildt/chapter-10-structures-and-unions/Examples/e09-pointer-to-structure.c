#include <stdio.h>
#include <string.h>

struct s_type {
    int i;
    char str[80];
} s, *p;

int main(void)
{
    p = &s;
    s.i = 10; // this is functionally the same
    p->i = 10; // as this
    strcpy(p->str, "I like structures.");

    printf("%d %d %s\n", s.i, p->i, p->str);

    return 0;
}