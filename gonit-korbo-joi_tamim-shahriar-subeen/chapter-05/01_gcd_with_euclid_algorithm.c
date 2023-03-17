# include <stdio.h>

int eucild_gcd(int a, int b) { 
/*
    Greatest Common Divisor(gcd) or গসাগু calcultion useing Euclid algorithm
    Euclid algorithm:-
        a ও b-এর গসাগু = (a - b) ও b-এর গসাগু
*/
    int temp;
    if (b > a) {
        temp = b;
        b = a;
        a = temp;
    }
    while (a != b) {
        if (b == 0) {
            break;
        }
        if (a > b) {
            a = a - b;
        }
        else {
            b = b - a;
        }
    }
    return a; // it return gcd of a and b
}

int main() {
    int a, b;

    printf("Enter the first number\t: ");
    scanf("%d", &a);
    printf("Enter the second number\t: ");
    scanf("%d", &b);

    
    printf("GCD is %d\n", eucild_gcd(a, b));


    return 0;
}