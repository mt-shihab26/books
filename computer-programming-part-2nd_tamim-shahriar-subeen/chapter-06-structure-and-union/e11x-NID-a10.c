#include <stdio.h>
#include <string.h>

typedef struct {
    char first[28];
    char second[28];
} name_type;

typedef struct {
    char day[3];
    char month[3];
    char year[5];
} date_of_birth_type;

typedef struct {
    name_type name, father_name, mother_name;
    date_of_birth_type date_of_birth;
    long id_no;
    char signature[28];
} nid_type;

int main(void)
{
    int t, i;
    // printf("Enter how many people you want to calculate: ");
    // scanf("%d", &t);
    nid_type people;
    // for (i = 0; i < t; i++) {
        char str[44];
        printf("Enter Name: ");
        scanf("%s", str);
        strcpy(people.name.first, str);
        scanf("%s", str);
        strcpy(people.name.second, str);

        printf("Enter Fathe's Name: ");
        scanf("%s", str);
        strcpy(people.father_name.first, str);
        scanf("%s", str);
        strcpy(people.father_name.second, str);

        printf("Enter Mother's Name: ");
        scanf("%s", str);
        strcpy(people.mother_name.first, str);
        scanf("%s", str);
        strcpy(people.mother_name.second, str);

        printf("Enter Date of Birth (day month year): ");
        scanf("%s", str);
        strcpy(people.date_of_birth.day, str);
        scanf("%s", str);
        strcpy(people.date_of_birth.month, str);
        scanf("%s", str);
        strcpy(people.date_of_birth.year, str);

        printf("Enter ID No: ");
        scanf("%ld", &people.id_no);
        printf("Enter Signature: ");
        scanf("%s", str);
        strcpy(people.signature, str);
    // }

    printf("\nOutput:\n\n");
    // for (i = 0; i < t; i++) {
        printf("Government of the People's Republic of Bangladesh\n\tNational ID Card\n\n");
        printf("Name: %s %s\n", people.name.first, people.name.second);
        printf("Father: %s %s\n", people.father_name.first, people.father_name.second);
        printf("Mother: %s %s\n", people.mother_name.first, people.mother_name.second);
        printf("Date of Birth: %s, %s, %s\n", people.date_of_birth.day, people.date_of_birth.month, people.date_of_birth.year);
        printf("ID NO: %ld\n", people.id_no);
        printf("Signature: %s\n\n\n", people.signature);
    // }
}