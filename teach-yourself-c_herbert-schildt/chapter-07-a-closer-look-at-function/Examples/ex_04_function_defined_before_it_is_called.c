#include <stdio.h>

// define getnum() prior to its first use
float getnum(void) {
    float x;
    printf("Enter a number: ");
    scanf("%f", &x);
    return x;
}

int main() {
    float i;

    i = getnum();
    printf("%f", i);

}