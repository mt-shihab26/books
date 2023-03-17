#include <stdio.h>

int main(void)
{
    int i;
     
    i = 1;

    jump_label:
        if (i >= 11) goto done_label;
        printf("%d ", i);
        i++;
        goto jump_label;
    done_label:
        printf("Done");

    return 0;
}