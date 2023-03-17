#include <stdio.h>

int main(void)
{
    int magic; // magic number
    int guess; // user's guess
    int i;

    magic = 1325;
    guess = 0;

    for (i=0; i<10 && guess!=magic; i++) {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess == magic) {
            printf("RIGHT!");
            printf(" %d is the magic number.\n", magic);
        }
        else {
            printf("...Sorry, you're wrong...");
            if (guess > magic) printf(" Your guess is too high.\n");
            else printf(" Your guess is too low.\n");
        }
    }

    return 0;
}