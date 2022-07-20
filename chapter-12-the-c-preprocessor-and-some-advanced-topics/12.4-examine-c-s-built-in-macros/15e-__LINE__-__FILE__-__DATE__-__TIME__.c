#include <stdio.h>

int main(void)
{
    printf("Compiling %s, line: %d, on %s, as %s\n", __FILE__, __LINE__, __DATE__, __TIME__);
    return 0;
}