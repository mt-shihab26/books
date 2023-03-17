#include <stdio.h>

typedef struct {
    char *name;
    char *phone;
    int work_h;
    int hourly_wages;
} employee_type;

int main(void)
{
    FILE *fp = fopen("emp_temp", "wb");
    if (fp == NULL) {
        printf("Can't open the file\n");
        return 1;
    }

    employee_type employee[10];
    for (int i=0; i<10; i++) {
        printf("Enter employee %d name, phone, work hours, hourly wages\n", i);
        scanf("%s %s %d %d", employee[i].name, employee[i].phone, &employee[i].work_h, &employee[i].hourly_wages);
    }
    fwrite(employee, sizeof(employee), 1, fp);
    fclose(fp);
    return 0;
}