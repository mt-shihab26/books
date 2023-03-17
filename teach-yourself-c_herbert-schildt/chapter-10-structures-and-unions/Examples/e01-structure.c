#include <stdio.h>

struct student_type{int id; char *name; int result;} student;

int main(void) {
    student.id = 1001;
    student.name = "Shihab Mahamud";
    student.result = 87;

    printf("%d %s %d", student.id, student.name, student.result);

    return 0;
}