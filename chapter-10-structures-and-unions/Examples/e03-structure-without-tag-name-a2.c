#include <stdio.h>

struct {
    int a;
    char ch;
} var1, var2;

int main(void)
{
    var1.a = 20;
    var1.ch = 'A';
    var2.a = 40;
    var2.ch = 'C';

    printf("%d %c\n%d %c\n", var1.a, var1.ch, var2.a, var2.ch);

    return 0;
}