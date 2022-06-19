#include <stdio.h>
#include <string.h>

int main() {
    char name[5][20] = {"Java", "Python", "C++", "HTML", "SQL"};
    char temp_num[20];
    int phones[5] = {111, 222, 333, 444, 555}, i;

    printf("Enter the name of the person whose phone number you want to see\n:");
    scanf("%s", temp_num);

    for (i = 0; i < 5; i++) {
        if (strcmp(name[i], temp_num) == 0) {
            printf("The number %s is %d\n", name[i] , phones[i]);
            return 0;
        }
    }

    return 0;
}