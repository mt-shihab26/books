#include <stdio.h>

#define NUM_ON_LINE 10

struct worker {
    char name[80];
    int avg_units_per_hour;
    int avg_errs_per_hour;
};

struct asm_line {
    int product_code;
    double material_cost;
    struct worker wkers[NUM_ON_LINE];
} line1, line2;

int main(void)
{
    line1.wkers[2].avg_units_per_hour = 12;

    return 0;
}