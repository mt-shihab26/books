#include <stdio.h>

int main(void)
{
    char players[9][21];
    double averages[9];
    int i;

    for (i = 0; i < 9; i++) {
        printf("Enter Players %d Name and Average: ", i+1);
        scanf("%s %lf", players[i], &averages[i]);
    }

    double highest = averages[0], lowest = averages[0], total_averages = 0;

    printf("\n");
    for (i = 0; i < 9; i++) {
        printf("Name: %s, Averages: %lf\n", players[i], averages[i]);
        if (highest < averages[i]) {
            highest = averages[i];
        }
        if (lowest > averages[i]) {
            lowest = averages[i];
        }
        total_averages += averages[i];
    }
    printf("\nHighest Average: %lf\nLowest Average: %lf\n\nTeam average: %lf\n", highest, lowest, total_averages/9.0);



    return 0;
}