#include <stdio.h>

int o_to_c(int ounces);

int main()
{
    printf("Cups: %d", o_to_c(10));

    return 0;
}

int o_to_c(int ounces)
{
    return ounces / 8;
}