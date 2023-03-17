#include <stdio.h>

int main(void)
{
    int proverb_number;

    printf("Enter proverb number: ");
    scanf("%d", &proverb_number);

    if (proverb_number == 1) printf("A bird in the hand...\n");
    if (proverb_number == 2) printf("Arolling stone...\n");
    if (proverb_number == 3) printf("Once buned, twice shy.\n");
    if (proverb_number == 4) printf("Early to bed, early to rise...\n");
    if (proverb_number == 5) printf("A penny saved in a penny earned.\n");

    return 0;
}