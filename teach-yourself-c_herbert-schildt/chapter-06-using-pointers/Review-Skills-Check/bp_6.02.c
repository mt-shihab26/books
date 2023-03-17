#include <stdio.h>
#include <string.h>
#define CR_PASSWD "Tristan"

int main() {
    char passwd[10];
    int i = 1;

    while (i <= 3) {
        printf("Please enter the Password: ");
        scanf("%s", passwd);
        if (strcmp(passwd, CR_PASSWD) == 0) {
            printf("Log-on Successfull!\n");
            return 0;
        }
        i++;
    }
    printf("Access Denied!\n");

    return 0;
}