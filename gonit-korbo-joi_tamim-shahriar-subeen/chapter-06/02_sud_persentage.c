#include <stdio.h>

int main() {
    int i, loan_amount, interest_rate, months;
    float total_amount;

    printf("Please enter the loan amount\n\t: ");
    scanf("%d", &loan_amount);
    printf("Please enter the interest rate\n\t: ");
    scanf("%d", &interest_rate);
    printf("After how many months you want to settle the loan?\n\t: ");
    scanf("%d", &months);

    // this is the amount before 1st month
    total_amount = loan_amount + loan_amount * interest_rate / 100.0;

    for (i = 1; i <= months; i++) {
        total_amount = total_amount + total_amount * interest_rate / 100.0;
        printf("After month %d, the total amount is %.f\n", i, total_amount);
    }    

    return 0;
}