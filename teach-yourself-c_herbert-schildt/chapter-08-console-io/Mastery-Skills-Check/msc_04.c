#include <stdio.h>

int main(void)
{
    char first[101], birth_date[101], phone[21];
    printf("Enter your First name: ");
    scanf("%s", first);
    printf("Enter Birth date (using the format mm/dd/yy): ");
    scanf("%s", birth_date);
    printf("Enter your phone number: ");
    scanf("%s", phone);

    printf("\n\n%s\n%s\n%s\n", first, birth_date, phone);

    return 0;
}