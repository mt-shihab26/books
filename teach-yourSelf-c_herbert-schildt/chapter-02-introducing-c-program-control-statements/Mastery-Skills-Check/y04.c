#include <stdio.h>

int main(void)
{
    int answer, count;
    int right, wrong;

    right = 0;
    wrong = 0;

    for (count=1; count<11; count++) {
        printf("What is %d + %d? ", count, count);
        scanf("%d", &answer);

        if (answer == count+count) {
            printf("Right! ");
            right++;
        }
        else {
            printf("Sorry, you're wrong. ");
            printf("The answer is %d.  ", count+count);
            wrong++;
        }
    }
    printf("You got %d right and %d wrong.", right, wrong);

    return 0;
}