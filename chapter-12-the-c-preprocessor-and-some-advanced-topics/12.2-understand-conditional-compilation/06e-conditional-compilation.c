#include <stdio.h>

/* define CHAR_SET as either 256 or 128 */
#define CHAR_SET 128

int main(void)
{
    int i;
#if CHAR_SET == 256
    printf("Displaying ASCII character set plus extensions.\n");
#else
    printf("Displaying only ASCII character set.\n");
#endif

    for (int i = 0; i < CHAR_SET; i++)
        printf("%c", i);
    printf("\n");
    return 0;
}