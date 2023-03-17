#include <stdio.h>

struct human
{
    char *name;
    char *date_of_barth;
    char *phone;
    int class;
};

typedef struct human human_type;

int main(void)
{
    human_type shihab = {.name = "Shihab Mahamud",
                         .date_of_barth = "26/09/2002",
                         .phone = "01758xxxxxx",
                         .class = 1002};

    printf("Name: %s\nDate of birth: %s\nPhone: %s\nClass = %d\n", shihab.name, shihab.date_of_barth, shihab.phone, shihab.class);
}