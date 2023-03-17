#include <stdio.h>
#include "../mine.h"

int main(void)
{
    FILE *values, *count_f;
    double temp;
    int count = 0;

    if ((values = fopen("VALUES", "w")) == NULL) {
        er_cn_op;
        return 1;
    }
            // fprintf(values, "%lf", 234.234);


    // writing the Values file 
    while (scanf("%lf", &temp) != EOF) {
        if (count == 32767) {
            break;
        }
        count++;
        if(fprintf(values, "%lf\n", temp) == EOF) {
            printf("Error Writing.\n");
            return 1;
        }
    }
    
    f_cl_er_ms(values, "VALUES", "r");

    if ((count_f = fopen("COUNT", "w")) == NULL) {
        er_cn_op;
        return 1;
    }

    fprintf(count_f, "%d", count);

    f_cl_er_ms(count_f, "COUNT", "w");

    return 0;
}