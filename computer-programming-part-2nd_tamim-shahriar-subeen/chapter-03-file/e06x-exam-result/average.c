#include <stdio.h>

int main(void)
{
    FILE *fp_math, *fp_english, *fp_bangla, *fp_average;
    fp_math = fopen("math.txt", "r");
    fp_english = fopen("english.txt", "r");
    fp_bangla = fopen("bangla.txt", "r");
    fp_average = fopen("average.txt", "w");

    int i, math_mark, english_mark, bangla_mark;
    float average_mark;

    while (fscanf(fp_math, "%d %d", &i, &math_mark) != EOF) {
        fscanf(fp_english, "%d %d", &i, &english_mark);
        fscanf(fp_bangla, "%d %d", &i, &bangla_mark);
        average_mark = ((float)(math_mark + english_mark + bangla_mark)) / 3;
        fprintf(fp_average, "%d %.2f\n", i, average_mark);
    }

    fclose(fp_math);
    fclose(fp_english);
    fclose(fp_bangla);
    fclose(fp_average);

    return 0;
}