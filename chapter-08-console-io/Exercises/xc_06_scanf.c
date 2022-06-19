#include <stdio.h>

int main(void)
{
    char first[21], middle[21], last[21];

    printf("Enter Your entire name: ");
    scanf("%20s %20s %20s", first, middle, last);
    printf("%s %s %s\n", first, middle, last);

    return 0;
}