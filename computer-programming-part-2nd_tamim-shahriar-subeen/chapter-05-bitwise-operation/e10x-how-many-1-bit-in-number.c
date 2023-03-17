#include <stdio.h>
#include <stdlib.h>

char *decimal_to_binary(int n);

int main(void)
{
    int num, i, count = 0;
    char *s_num;

    printf("Enter your number: ");
    scanf("%d", &num);

    s_num = decimal_to_binary(num);
    for (i = 0; s_num[i]; i++) {
        if (s_num[i] == '1')
            count++; 
    }

    printf("Number of 1: %d\n", count);

    return 0;
}

char *decimal_to_binary(int n)
{
    int c, d, t;
    char *p;

    t = 0;
    p = (char *)malloc(32 + 1);

    if (p == NULL)
        exit(EXIT_FAILURE);

    for (c = 31; c >= 0; c--) {
        d = n >> c;

        if (d & 1)
            *(p + t) = 1 + '0';
        else
            *(p + t) = 0 + '0';

        t++;
    }
    *(p + t) = '\0';

    return p;
}