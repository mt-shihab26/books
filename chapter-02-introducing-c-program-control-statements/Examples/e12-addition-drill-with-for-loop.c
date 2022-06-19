#include <stdio.h>

int main(void)
{
    int answer, count;

    for (count=1; count<11; count=count+1) {
        printf("What is %d + %d? ", count, count);
        scanf("%d", &answer);

        if (answer == count+count) printf("Right!");
        else {
            printf("Sorry, you're wrong. ");
            printf("The answer is %d. ", count+count);
        }
    }

    return 0;
}