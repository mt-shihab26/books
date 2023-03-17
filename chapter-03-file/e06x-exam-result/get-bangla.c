#include <stdio.h>

int main(void)
{
    FILE *fp = fopen("bangla.txt", "w");
    int i, mark;

    for (i = 1; i <= 10; i++) {
        printf("Roll %d: bangla mark: ", i);
        scanf("%d", &mark);
        fprintf(fp, "%d %d\n", i, mark);
    }
    fclose(fp);

    return 0;
}