#include <stdio.h>

#define DOG

int main(void)
{
#ifdef DOG
    printf("DOG is defined.\n");
#endif

#undef DOG

#ifdef DOG
    printf("This line is not compiled.\n");
#endif
}