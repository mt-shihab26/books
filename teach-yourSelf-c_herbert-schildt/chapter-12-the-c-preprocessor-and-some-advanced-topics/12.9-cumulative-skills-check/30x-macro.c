#include <stdio.h>
#include <stdlib.h>

char code_it(char c)
{
    return -c;
}

#define code_it2(c) -(c)

int main()
{
    printf("%d\n", code_it('a'));
    printf("%d\n", code_it2('a'));

    return 0;
}