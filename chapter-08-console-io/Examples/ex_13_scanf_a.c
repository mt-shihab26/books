#include <stdio.h>

int main(void)
{
    char str[80];

    printf("Enter letters, anyting else to stop\n");
    scanf("%[a-zA-Z]", str);

    printf(str);

    return 0;
}