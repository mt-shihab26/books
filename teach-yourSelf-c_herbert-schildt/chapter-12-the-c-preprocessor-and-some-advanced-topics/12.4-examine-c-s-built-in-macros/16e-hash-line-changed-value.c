#include <stdio.h>

int main(void)
{
#line 100 "myprog.c"
    printf("Compiling %s, line: %d, on %s, as %s\n", __FILE__, __LINE__, __DATE__, __TIME__);
    return 0;
}