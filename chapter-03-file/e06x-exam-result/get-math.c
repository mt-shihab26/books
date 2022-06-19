#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("math.txt", "w");

    int mark, i;

    for (i = 1; i <= 10; i++) {
        printf("Roll %d: math mark: ", i);
        scanf("%d", &mark);
        fprintf(fp, "%d %d\n", i, mark);
    }
    fclose(fp);

    return 0;
}