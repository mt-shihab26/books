#include <stdio.h>

int main() {
    int months, rent_per_month;
    float agent_fee, agent_percentage;

    printf("What is your rent? \n: ");
    scanf("%d", &rent_per_month);

    printf("For how many months you are renting?\n: ");
    scanf("%d", &months);

    agent_percentage = (100.00 / 12) * months;
    agent_fee = rent_per_month * agent_percentage / 100;
    printf("Agent fee is %.2f\n", agent_fee);

    return 0;
}