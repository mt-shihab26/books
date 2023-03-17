#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    double *p = malloc(10 * sizeof(double));
    if (!p)
    {
        printf("Allocation Error");
        return 1;
    }
    FILE *fp;

    // generate 10 random numbers
    for (i = 0; i < 10; i++)
        p[i] = (double)rand();

    if ((fp = fopen("myfile", "wb")) == NULL)
    {
        printf("Cannot open file.\n");
        return 1;
    }

    // write the entire array in one step
    if (fwrite(p, 10 * sizeof(double), 1, fp) != 1)
    {
        printf("Write Error\n");
        return 1;
    }
    fclose(fp);

    free(p); // memory not needed now

    /*
    imagine something transpires here


    */

    // get memory again
    p = malloc(10 * sizeof(double));
    if (!p)
    {
        printf("Allocation Error");
        return 1;
    }

    if ((fp = fopen("myfile", "rb")) == NULL)
    {
        printf("Cannot open file.\n");
        return 1;
    }

    if (fread(p, 10 * sizeof(double), 1, fp) != 1)
    {
        printf("Read Error.\n");
        return 1;
    }

    fclose(fp);

    // display the array
    for (i = 0; i < 10; i++)
        printf("%f", p[i]);

    free(p);

    return 0;
}
