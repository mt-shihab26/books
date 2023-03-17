#include <stdio.h>

#define TESTPROJECT 29

#if defined TESTPROJECT
int main(void)
{
    printf("This is test.\n");
    return 0;
}
#endif