#include <stdio.h>

int main()
{
    int ft_marks[40], st_marks[40], final_marks[40];
    int i, j;
    double total_marks[40];

    printf("Enter the ft_marks:\n");
    for (i = 0; i < 40; i++) {
        printf("Roll-%d: ", i+1);
        scanf("%d", &ft_marks);
    }
    printf("Enter the st_marks:\n");
    for (i = 0; i < 40; i++) {
        printf("Roll-%d: ", i+1);
        scanf(" %d", &st_marks);
    }
    printf("Enter the final_marks:\n");
    for (i = 0; i < 40; i++) {
        printf("Roll-%d: ", i+1);
        scanf(" %d", &final_marks);
    }



    for (i = 0; i < 40; i += 1)
    {
        total_marks[i] = (ft_marks[i] / 4.0) + (st_marks[i] / 4.0) + (final_marks[i] / 2.0);
    }
    for (i = 1; i <= 40; i += 1)
    {
        printf("Roll no: %d\tTotal Marks: %.2lf\n", i, total_marks[i - 1]);
    }

    return 0;
}