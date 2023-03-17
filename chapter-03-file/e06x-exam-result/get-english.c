#include <stdio.h>

int main(void)
{
    FILE *fp;
    fp = fopen("english.txt", "w");
    int i, mark;

    for (i = 1; i <= 10; i++) {
        printf("Roll %d: english mark: ", i);
        scanf("%d", &mark);
        fprintf(fp, "%d %d\n", i, mark);
    }
    fclose(fp);
}