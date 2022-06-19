#include <stdio.h>

void prompt(char *msg, int *num);

int main(void) {
    int i;
    prompt("Enter a num: ", &i);
    printf("Your number is: %d\n", i);
}

void prompt(char *msg, int *num) {
    printf(msg);
    scanf("%d", num);
}

// Date: শুক্রবার, ফেব্রুয়ারী 26, 2021 | 18:48:27
