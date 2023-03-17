#include <stdio.h>

int main() 
{
    FILE *valuesp, *countp;
    double temp;
    int count;

    if ((countp = fopen("COUNT", "r")) == NULL) {
        printf("Cannot open COUNT file.\n");
        return 1;
    }
    fscanf(countp, "%d", &count);

    if ((valuesp = fopen("VALUES", "r")) == NULL) {
        printf("Cannot open VALUES file.\n");
        return 1;
    }

    while (count--) {
        fscanf(valuesp, "%lf", &temp);
        printf("%lf\n", temp);
    }
    

    return 0;
}
